/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>
#include "neopixel.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

enum LEDStringState_E
{
  IDLE_ANIMATION,
  PROPOSAL_ANIMATION,
  VICTORY_ANIMATION,
  NUM_OF_LED_STATEMAP_STATES
};

struct GPIO_Port_Pin_S
{
  GPIO_TypeDef * port;
  uint16_t pin;
};

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define DEBOUNCE_WAIT_TIME  5 // ms

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;
DMA_HandleTypeDef hdma_tim2_ch1;
DMA_HandleTypeDef hdma_tim3_ch1;
DMA_HandleTypeDef hdma_tim4_ch1;

UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */

static volatile bool DMA_Transfer_Complete; // Flag to indicate a DMA transfer was completed. TODO: Remove this once you figure how to get around the wait after DMA transfer request...
static volatile bool ButtonPressed;

/* External variables --------------------------------------------------------*/

extern const struct LED_Strip_Frame_S LED_ANIMATION_TABLE[NUM_OF_FRAMES];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM4_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/*!*****************************************************************
* @fn HAL_TIM_PWM_PulseFinishedCallback
* @brief Callback function that is called once the DMA has completed its transfer.
* @param[in] PixelData array that contains the data for each pixel
* @return void
*******************************************************************/
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
  HAL_TIM_PWM_Stop_DMA( htim, TIM_CHANNEL_1 );
  DMA_Transfer_Complete = true;
}

/**
  * @brief  EXTI line detection callback.
  * @param  GPIO_Pin: Specifies the port pin connected to corresponding EXTI line.
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if ( GPIO_Pin == B1_Pin )
  {
    ButtonPressed = true;
  }
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  static enum LEDStringState_E LEDStateMapState = IDLE_ANIMATION;
  static bool AnimationComplete = false;
  static uint8_t LED_Idx = 0;
  static bool StateUpdated = false;
  uint32_t dma_buffer_ring_strip[NUM_OF_PIXELS_IN_RING_STRIP * NUM_OF_BITS_PER_PIXEL + 1];
  uint32_t dma_buffer_pulse_strip[NUM_OF_PIXELS_IN_PULSE_STRIP * NUM_OF_BITS_PER_PIXEL + 1];

  // Declarations and definitions for LED selection
  static const struct GPIO_Port_Pin_S LED_OPTIONS_TABLE[] =
  {
    { LD1_GPIO_Port,  LD1_Pin },
    { LD2_GPIO_Port,  LD2_Pin },
    { LD3_GPIO_Port,  LD3_Pin },
  };

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART3_UART_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_GPIO_WritePin( LED_OPTIONS_TABLE[LED_Idx].port, LED_OPTIONS_TABLE[LED_Idx].pin, GPIO_PIN_SET );

  while (1)
  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

    switch( LEDStateMapState )
    {
      case IDLE_ANIMATION:
        StateUpdated = false;

        NeoPixel_RingStrip_AllOff_FillBuffer(dma_buffer_ring_strip, sizeof(dma_buffer_ring_strip)/sizeof(uint32_t));
        NeoPixel_PulseStrips_AllOff_FillBuffer(dma_buffer_pulse_strip, sizeof(dma_buffer_pulse_strip)/sizeof(uint32_t));

        // Send away to timer 4
        if ( HAL_TIM_PWM_Start_DMA( &htim4, TIM_CHANNEL_1, dma_buffer_ring_strip, sizeof(dma_buffer_ring_strip)/sizeof(uint32_t) ) != HAL_OK )
        {
          // TODO: Write a handler to indicate the DMA start request failed...
        }
        while( DMA_Transfer_Complete == false );
        DMA_Transfer_Complete = false;

        // Send away to the timer 2
        if ( HAL_TIM_PWM_Start_DMA( &htim2, TIM_CHANNEL_1, dma_buffer_pulse_strip, sizeof(dma_buffer_pulse_strip)/sizeof(uint32_t) ) != HAL_OK )
        {
          // TODO: Write a handler to indicate the DMA start request failed...
        }
        // For some reason, despite this defeating the whole purpose of the DMA, I have to wait otherwise the data gets corrupted...
        // TODO: Figure out how to not have to do this!
        while( DMA_Transfer_Complete == false );
        DMA_Transfer_Complete = false;

        // Send away to the timer 3
        if ( HAL_TIM_PWM_Start_DMA( &htim3, TIM_CHANNEL_1, dma_buffer_pulse_strip, sizeof(dma_buffer_pulse_strip)/sizeof(uint32_t) ) != HAL_OK )
        {
          // TODO: Write a handler to indicate the DMA start request failed...
        }
        while( DMA_Transfer_Complete == false );
        DMA_Transfer_Complete = false;


        // Process button press, if applicable
        if ( ButtonPressed == true )
        {
          StateUpdated = true;
          AnimationComplete = false;
          LEDStateMapState = PROPOSAL_ANIMATION; // Next loop will transition to next state
          ButtonPressed = false;
          HAL_Delay( DEBOUNCE_WAIT_TIME );  // TODO: Handle debounces without a delay...

          // For debug purposes, drive one of the board LEDs to indicate state
          HAL_GPIO_WritePin( LED_OPTIONS_TABLE[LED_Idx].port, LED_OPTIONS_TABLE[LED_Idx].pin, GPIO_PIN_RESET );
          LED_Idx++;
          // Wrap-around if past table bounds
          if ( LED_Idx >= (sizeof(LED_OPTIONS_TABLE) / sizeof(struct GPIO_Port_Pin_S)) )
          {
            LED_Idx = 0;
          }
          HAL_GPIO_WritePin( LED_OPTIONS_TABLE[LED_Idx].port, LED_OPTIONS_TABLE[LED_Idx].pin, GPIO_PIN_SET );

        }

        break;

      case PROPOSAL_ANIMATION:

        // Process button press, if applicable
        if ( ButtonPressed == true )
        {
          if ( AnimationComplete == false )
          {
            // Hold off on transitioning
          }
          else
          {
            LEDStateMapState = VICTORY_ANIMATION; // Next loop will transition to next state
            ButtonPressed = false;
            HAL_Delay( DEBOUNCE_WAIT_TIME );  // TODO: Handle debounces without a delay...

            // For debug purposes, drive one of the board LEDs to indicate state
            HAL_GPIO_WritePin( LED_OPTIONS_TABLE[LED_Idx].port, LED_OPTIONS_TABLE[LED_Idx].pin, GPIO_PIN_RESET );
            LED_Idx++;
            // Wrap-around if past table bounds
            if ( LED_Idx >= (sizeof(LED_OPTIONS_TABLE) / sizeof(struct GPIO_Port_Pin_S)) )
            {
              LED_Idx = 0;
            }
            HAL_GPIO_WritePin( LED_OPTIONS_TABLE[LED_Idx].port, LED_OPTIONS_TABLE[LED_Idx].pin, GPIO_PIN_SET );
          }

        }

        // Animate!
        if ( AnimationComplete == false )
        {

          for ( uint8_t pulse_idx = 1; pulse_idx < (NUM_OF_BRIGHTNESS_LEVELS - 1); pulse_idx++ )
          {
            // Perform pulse animation

            // Pulse one strip
            for ( uint8_t frame_idx = 0; frame_idx < NUM_OF_FRAMES; frame_idx++ )
            {
              NeoPixel_PulseStrips_FillBuffer( frame_idx, dma_buffer_pulse_strip, sizeof(dma_buffer_pulse_strip)/sizeof(uint32_t) );
              // Send away to the timer 2
              if ( HAL_TIM_PWM_Start_DMA( &htim2, TIM_CHANNEL_1, dma_buffer_pulse_strip, sizeof(dma_buffer_pulse_strip)/sizeof(uint32_t) ) != HAL_OK )
              {
                // TODO: Write a handler to indicate the DMA start request failed...
              }
              // For some reason, despite this defeating the whole purpose of the DMA, I have to wait otherwise the data gets corrupted...
              // TODO: Figure out how to not have to do this!
              while( DMA_Transfer_Complete == false );
              DMA_Transfer_Complete = false;

              HAL_Delay(15);  // REDO COMMENT: 1s / 30 frames ~ 33.333ms, and it takes about 30us x 60 LEDs x 2 strips = 3.6ms to update the strips, so 33.333ms - 3.600ms = 29.733ms ~ 30ms
            }

            // Go to next brightness level with the ring strip
            NeoPixel_RingStrip_FillBuffer( (enum RingBrightness_E) pulse_idx, dma_buffer_ring_strip, sizeof(dma_buffer_ring_strip)/sizeof(uint32_t) );
            if ( HAL_TIM_PWM_Start_DMA( &htim4, TIM_CHANNEL_1, dma_buffer_ring_strip, sizeof(dma_buffer_ring_strip)/sizeof(uint32_t) ) != HAL_OK )
            {
              // TODO: Write a handler to indicate the DMA start request failed...
            }
            while( DMA_Transfer_Complete == false );
            DMA_Transfer_Complete = false;
            pulse_idx++;

            // Pulse the other strip
            for ( uint8_t frame_idx = 0; frame_idx < NUM_OF_FRAMES; frame_idx++ )
            {
              NeoPixel_PulseStrips_FillBuffer( frame_idx, dma_buffer_pulse_strip, sizeof(dma_buffer_pulse_strip)/sizeof(uint32_t) );

              // Send away to the timer 3
              if ( HAL_TIM_PWM_Start_DMA( &htim3, TIM_CHANNEL_1, dma_buffer_pulse_strip, sizeof(dma_buffer_pulse_strip)/sizeof(uint32_t) ) != HAL_OK )
              {
                // TODO: Write a handler to indicate the DMA start request failed...
              }
              while( DMA_Transfer_Complete == false );
              DMA_Transfer_Complete = false;

              HAL_Delay(15);  // REDO COMMENT: 1s / 30 frames ~ 33.333ms, and it takes about 30us x 60 LEDs x 2 strips = 3.6ms to update the strips, so 33.333ms - 3.600ms = 29.733ms ~ 30ms
            }

            // Go to next brightness level with the ring strip
            NeoPixel_RingStrip_FillBuffer( (enum RingBrightness_E) pulse_idx, dma_buffer_ring_strip, sizeof(dma_buffer_ring_strip)/sizeof(uint32_t) );
            if ( HAL_TIM_PWM_Start_DMA( &htim4, TIM_CHANNEL_1, dma_buffer_ring_strip, sizeof(dma_buffer_ring_strip)/sizeof(uint32_t) ) != HAL_OK )
            {
              // TODO: Write a handler to indicate the DMA start request failed...
            }
            while( DMA_Transfer_Complete == false );
            DMA_Transfer_Complete = false;

          }

          AnimationComplete = true;

        }
        else
        {
          // Do nothing. Hold at last animation frame!
          // TODO: Pulse the ring?
        }

        break;

      case VICTORY_ANIMATION:

        // Process button press, if applicable
        if ( ButtonPressed == true )
        {

          AnimationComplete = false;
          LEDStateMapState = IDLE_ANIMATION; // Next loop will transition to next state
          ButtonPressed = false;
          HAL_Delay( DEBOUNCE_WAIT_TIME );  // TODO: Handle debounces without a delay...

          // For debug purposes, drive one of the board LEDs to indicate state
          HAL_GPIO_WritePin( LED_OPTIONS_TABLE[LED_Idx].port, LED_OPTIONS_TABLE[LED_Idx].pin, GPIO_PIN_RESET );
          LED_Idx++;
          // Wrap-around if past table bounds
          if ( LED_Idx >= (sizeof(LED_OPTIONS_TABLE) / sizeof(struct GPIO_Port_Pin_S)) )
          {
            LED_Idx = 0;
          }
          HAL_GPIO_WritePin( LED_OPTIONS_TABLE[LED_Idx].port, LED_OPTIONS_TABLE[LED_Idx].pin, GPIO_PIN_SET );

        }

        break;

    }

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 80-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 80-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 0;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 80-1;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */
  HAL_TIM_MspPostInit(&htim4);

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart3, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart3, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream0_IRQn);
  /* DMA1_Stream1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream1_IRQn);
  /* DMA1_Stream2_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream2_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(USB_OTG_FS_PWR_EN_GPIO_Port, USB_OTG_FS_PWR_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PC1 PC4 PC5 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA1 PA2 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LD1_Pin LD3_Pin */
  GPIO_InitStruct.Pin = LD1_Pin|LD3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PB13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_OTG_FS_PWR_EN_Pin */
  GPIO_InitStruct.Pin = USB_OTG_FS_PWR_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(USB_OTG_FS_PWR_EN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_OTG_FS_OVCR_Pin */
  GPIO_InitStruct.Pin = USB_OTG_FS_OVCR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USB_OTG_FS_OVCR_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PA8 PA11 PA12 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF10_OTG1_FS;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PG11 PG13 */
  GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
