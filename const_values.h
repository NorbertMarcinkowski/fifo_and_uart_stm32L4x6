#pragma once

#include <stdio.h>
#include <stdint.h>


#define PERP_START                    (0x40000000UL)

#define AHB1_BASE        (PERP_START + 0x00020000UL)
#define RCC_BASE         (0x40021000)
#define PWR_BASE         (PERP_START + 0x7000UL)
#define Fclk 4000000


#define CLOCK_GPIO_A                ((uint16_t)0x0001)
#define CLOCK_GPIO_B                ((uint16_t)0x0002)
#define CLOCK_GPIO_C                ((uint16_t)0x0004)
#define CLOCK_GPIO_D                ((uint16_t)0x0008)
#define CLOCK_GPIO_E                ((uint16_t)0x0010)
#define CLOCK_GPIO_F                ((uint16_t)0x0020)
#define CLOCK_GPIO_G                ((uint16_t)0x0040)
#define CLOCK_GPIO_H                ((uint16_t)0x0080)

#define SET    1
#define RESET  0
