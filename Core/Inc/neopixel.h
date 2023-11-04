/**
  ******************************************************************************
  * @file           : neopixel.h
  * @brief          : Types and definitions for objects related to driving the
  *                   NeoPixel LED string.
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

#ifndef NEOPIXEL_H_      // Multi-include protection
#define NEOPIXEL_H_


/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>

/* Public define ------------------------------------------------------------*/

#define NUM_OF_PIXELS_IN_PULSE_STRIP        60
#define NUM_OF_PIXELS_IN_RING_STRIP         100
#define NUM_OF_BITS_PER_PIXEL               24
#define NUM_OF_FRAMES_PER_SECOND            30
#define NUM_OF_SECONDS_OF_UNIQUE_ANIMATION  1
#define NUM_OF_FRAMES                       (NUM_OF_FRAMES_PER_SECOND * NUM_OF_SECONDS_OF_UNIQUE_ANIMATION)

#define LED_SETPOINT_MIN  0
#define LED_SETPOINT_MAX  255

#define ARR_SETPOINT                (80-1)  // ARR = Auto-Reload Register --> Register that sets the PWM frequency and is what effectively sets the reset point of the timer's counter
// Duty cycle is set in the Capture/Compare Register (CRR) of a timer respective output channel, and is what effectively sets the point at which the PWM center edge occurs.
#define DUTY_CYCLE_100_PCT          ARR_REGISTER_SETPOINT
#define DUTY_CYCLE_0_PCT            0
#define DUTY_CYCLE_ZERO_ENCODING    22  // 22 / 80 ~ 0.275 ==> 0.275 x 1,250ns = 343.8ns = 350ns - 6.2ns (which is within +/- 150ns spec)
#define DUTY_CYCLE_ONE_ENCODING     45  // 45 / 80 ~ 0.560 ==> 0.560 x 1,250ns = 703.1ns = 700ns + 3.1ns (which is within +/- 150ns spec)
#define DUTY_CYCLE_STOP_ENCODING    0   // Line needs to be low for at least 50us for the transmission to be interpreted as complete by the WS2812 module

/* Public typedef -----------------------------------------------------------*/

typedef uint8_t LEDSetpoint_T;  // Setpoint for a given LED is a value from 0 to 255, which is the same range as a byte

// For convenience of looping through the bits for the LEDs, I'll want to place the LSB first and MSB last (since ARM is little-endian)
struct Pixel_S
{
  LEDSetpoint_T blue;   // Will become LSB
  LEDSetpoint_T red;
  LEDSetpoint_T green;  // Will become MSB
};

union Pixel_U
{
  // TODO: Need to note whether the struct will take up the lower 3 bytes or the upper 3 bytes of this space...
  struct Pixel_S rgb;
  uint32_t pixel_word;
};

struct LED_Strip_Frame_S
{
    union Pixel_U LEDs[NUM_OF_PIXELS_IN_PULSE_STRIP];
};

enum RingBrightness_E
{
  BRIGHTNESS_OFF,
  BRIGHTNESS_MIN,
  BRIGHTNESS_LEVEL_1 = BRIGHTNESS_MIN,
  BRIGHTNESS_LEVEL_2,
  BRIGHTNESS_LEVEL_3,
  BRIGHTNESS_LEVEL_4,
  BRIGHTNESS_LEVEL_5,
  BRIGHTNESS_MID = BRIGHTNESS_LEVEL_5,
  BRIGHTNESS_LEVEL_6,
  BRIGHTNESS_LEVEL_7,
  BRIGHTNESS_LEVEL_8,
  BRIGHTNESS_LEVEL_9,
  BRIGHTNESS_LEVEL_10,
  BRIGHTNESS_MAX = BRIGHTNESS_LEVEL_10,
  NUM_OF_BRIGHTNESS_LEVELS
};

/* Private macro -------------------------------------------------------------*/



/* Private variables ---------------------------------------------------------*/



/* Public function prototypes ------------------------------------------------*/

bool NeoPixel_PulseStrips_FillBuffer(uint8_t frame, uint32_t * buffer, uint32_t length);
bool NeoPixel_RingStrip_FillBuffer(enum RingBrightness_E brightness, uint32_t * buffer, uint32_t length);

/* Private user code ---------------------------------------------------------*/

#endif  // NEOPIXEL_H