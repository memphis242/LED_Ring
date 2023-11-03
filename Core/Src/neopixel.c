/**
  ******************************************************************************
  * @file           : neopixel.c
  * @brief          : Function and table definitions for driving the NeoPixels.
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
 
/* Includes ------------------------------------------------------------------*/
#include "neopixel.h"
#include <stddef.h>


/* Private typedef -----------------------------------------------------------*/



/* Private define ------------------------------------------------------------*/



/* Private macro -------------------------------------------------------------*/



/* Public variables ---------------------------------------------------------*/
const struct LED_Strip_Frame_S LED_ANIMATION_TABLE[NUM_OF_FRAMES] =
{
    {
        .LEDs =
        {   // 0
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 1
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 2
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 3
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 4
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 5
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 6
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 7
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 8
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 9
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 10
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 11
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 12
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 13
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 14
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
        },
    },

    {
        .LEDs =
        {   // 15
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
        },
    },

    {
        .LEDs =
        {   // 16
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 17
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
        },
    },

    {
        .LEDs =
        {   // 18
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 19
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 20
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 21
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 22
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 23
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 24
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     }
        },
    },

    {
        .LEDs =
        {   // 25
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
        },
    },

    {
        .LEDs =
        {   // 26
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
        },
    },

    {
        .LEDs =
        {   // 27
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
        },
    },

    {
        .LEDs =
        {   // 28
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
        },
    },

    {
        .LEDs =
        {   // 29
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },

            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=0,   .rgb.red=0,   .rgb.blue=0     },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
            { .rgb.green=255, .rgb.red=255, .rgb.blue=255   },
        },
    },
};

/*----------------------------------------------------------------------------------------------------
 * Brightness follows the curve:
 *      B[n] = 10 x exp( 0.684 x n )
 * an exponential curve which is hopefully
 * perceived as a linear increase in brightness (a linearly increasing command does not get perceived
 * as an even, linear increased in brightness).
------------------------------------------------------------------------------------------------------*/
const uint32_t LED_BRIGHTNESS_TABLE[NUM_OF_BRIGHTNESS_LEVELS] =
{
  0,    // BRIGHTNESS_OFF
  19,   // BRIGHTNESS_MIN / LEVEL 1
  37,   // BRIGHTNESS_LEVEL_2
  70,   // BRIGHTNESS_MID / LEVEL 3
  134,  // BRIGHTNESS_LEVEL_4
  255,  // BRIGHTNESS_MAX / LEVEL_5
};

/* Private variables ---------------------------------------------------------*/



/* Private function prototypes -----------------------------------------------*/



/* Public function definitions -----------------------------------------------*/

/*!*****************************************************************
* @fn NeoPixel_PulseStrips_FillBuffer
* @brief Fills the passed in buffer with the right duty cycle data
*        based on the passed-in frame.
* @param[in] frame uint8_t frame of the animation
* @param[in] buffer uint32_t * buffer to hold duty cycle data
* @param[in] length length of passed-in buffer --> NEEDS to be (NUM_OF_PIXELS_IN_RING_STRING * NUM_OF_BITS_PER_PIXEL + 1)
* @param[in] LED_ANIMATION_TABLE data for each pixel for this frame
* @return bool - Success (true) or Fail (false)
*******************************************************************/
bool NeoPixel_PulseStrips_FillBuffer(uint8_t frame, uint32_t * buffer, uint32_t length)
{
  bool retVal = true;

  // Verify input parameters
  if ( frame > (NUM_OF_FRAMES - 1) ||
       buffer == NULL ||
       length != (NUM_OF_PIXELS_IN_PULSE_STRIP * NUM_OF_BITS_PER_PIXEL + 1) )
  {
    // TODO: Some assert
    retVal = false;
  }

  else
  {
    // The last duty cycle will be set to zero to ensure line is off.
    // TODO: Evaluate the proper way to set the line low (turn off timer? turn off output enable?)
    buffer[length - 1] = DUTY_CYCLE_0_PCT;

    // Iterate through each pixel's setpoint and populate the PWM duty cycle data accordingly
    // Remember to send the most-signficant bit of each LED's setpoint _first_.
    // --> I accomplish this by having the pixel data organized MSB first and looping from MSb to LSb.
    unsigned int duty_cycle_idx = 0;
    for ( unsigned int pixel_idx = 0; pixel_idx < NUM_OF_PIXELS_IN_PULSE_STRIP; pixel_idx++ )
    {
      for ( int8_t bit_idx = (NUM_OF_BITS_PER_PIXEL - 1); bit_idx >= 0 ; bit_idx-- )
      {
        if ( ( (LED_ANIMATION_TABLE[frame].LEDs[pixel_idx].pixel_word >> bit_idx) & 0x00000001u ) > 0 )
        {
            buffer[duty_cycle_idx] = DUTY_CYCLE_ONE_ENCODING;
        }
        else
        {
            buffer[duty_cycle_idx] = DUTY_CYCLE_ZERO_ENCODING;
        }

        duty_cycle_idx++;
      }
    }
  }

  return retVal;
}


/*!*****************************************************************
* @fn NeoPixel_RingStrip_FillBuffer
* @brief Fills the passed in buffer with the right duty cycle data
*        based on the passed-in brightness level.
* @param[in] brightness enum RingBrightness_E A brightness level, used to index into LED_BRIGHTNESS_TABLE
* @param[in] buffer uint32_t * buffer to hold duty cycle data
* @param[in] length length of passed-in buffer --> NEEDS to be (NUM_OF_PIXELS_IN_RING_STRING * NUM_OF_BITS_PER_PIXEL + 1)
* @param[in] LED_BRIGHTNESS_TABLE data for each pixel for this frame
* @return bool - Success (true) or Fail (false)
*******************************************************************/
bool NeoPixel_RingStrip_FillBuffer(enum RingBrightness_E brightness, uint32_t * buffer, uint32_t length)
{
  bool retVal = true;

  // Verify input parameters
  if ( brightness > (NUM_OF_BRIGHTNESS_LEVELS - 1) ||
       buffer == NULL ||
       length != (NUM_OF_PIXELS_IN_RING_STRIP * NUM_OF_BITS_PER_PIXEL + 1) )
  {
    // TODO: Some assert
    retVal = false;
  }

  else
  {
    // The last duty cycle will be set to zero to ensure line is off.
    // TODO: Evaluate the proper way to set the line low (turn off timer? turn off output enable?)
    buffer[length - 1] = DUTY_CYCLE_0_PCT;

    uint8_t brightness_level = LED_BRIGHTNESS_TABLE[brightness];
    uint32_t brightness_rgb = (brightness_level << 16) | (brightness_level << 8) | brightness_level;
    // Iterate through each pixel's setpoint and populate the PWM duty cycle data accordingly
    // Remember to send the most-signficant bit of each LED's setpoint _first_.
    // --> I accomplish this by having the pixel data organized MSB first and looping from MSb to LSb.
    unsigned int duty_cycle_idx = 0;
    for ( unsigned int pixel_idx = 0; pixel_idx < NUM_OF_PIXELS_IN_RING_STRIP; pixel_idx++ )
    {
      for ( int8_t bit_idx = (NUM_OF_BITS_PER_PIXEL - 1); bit_idx >= 0 ; bit_idx-- )
      {
        if ( ( (brightness_rgb >> bit_idx) & 0x00000001u ) > 0 )
        {
            buffer[duty_cycle_idx] = DUTY_CYCLE_ONE_ENCODING;
        }
        else
        {
            buffer[duty_cycle_idx] = DUTY_CYCLE_ZERO_ENCODING;
        }

        duty_cycle_idx++;
      }
    }
  }

  return retVal;
}


/* Private function definitions ----------------------------------------------*/

