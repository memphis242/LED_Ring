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

/* Public define ------------------------------------------------------------*/

#define NUM_OF_PIXELS_IN_STRIP              60
#define NUM_OF_BITS_PER_PIXEL               24
#define NUM_OF_FRAMES_PER_SECOND            30
#define NUM_OF_SECONDS_OF_UNIQUE_ANIMATION  1
#define NUM_OF_FRAMES                       (NUM_OF_FRAMES_PER_SECOND * NUM_OF_SECONDS_OF_UNIQUE_ANIMATION)

#define LED_SETPOINT_MIN  0
#define LED_SETPOINT_MAX  255

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
    union Pixel_U LEDs[NUM_OF_PIXELS_IN_STRIP];
};

/* Private macro -------------------------------------------------------------*/



/* Private variables ---------------------------------------------------------*/



/* Private function prototypes -----------------------------------------------*/




/* Private user code ---------------------------------------------------------*/

#endif  // NEOPIXEL_H