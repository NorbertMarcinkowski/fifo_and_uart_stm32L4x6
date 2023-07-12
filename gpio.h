#pragma once

#include "const_values.h"

#define GPIO_BASE_START            (PERP_START + 0x08000000UL)
#define GPIOA_BASE_START            (GPIO_BASE_START + 0x0000UL)
#define GPIOB_BASE_START            (GPIO_BASE_START + 0x0400UL)
#define GPIOC_BASE_START            (GPIO_BASE_START + 0x0800UL)
#define GPIOD_BASE_START            (GPIO_BASE_START + 0x0C00UL)
#define GPIOE_BASE_START            (GPIO_BASE_START + 0x1000UL)
#define GPIOF_BASE_START            (GPIO_BASE_START + 0x1400UL)
#define GPIOG_BASE_START            (GPIO_BASE_START + 0x1800UL)
#define GPIOH_BASE_START            (GPIO_BASE_START + 0x1C00UL)

#define GPIO_BASE_START            (PERP_START + 0x08000000UL)

#define GPIOA_BASE_START            (GPIO_BASE_START + 0x0000UL)
#define GPIOB_BASE_START            (GPIO_BASE_START + 0x0400UL)
#define GPIOC_BASE_START            (GPIO_BASE_START + 0x0800UL)
#define GPIOD_BASE_START            (GPIO_BASE_START + 0x0C00UL)
#define GPIOE_BASE_START            (GPIO_BASE_START + 0x1000UL)
#define GPIOF_BASE_START            (GPIO_BASE_START + 0x1400UL)
#define GPIOG_BASE_START            (GPIO_BASE_START + 0x1800UL)
#define GPIOH_BASE_START            (GPIO_BASE_START + 0x1C00UL)

#define GPIO_PIN_0                    ((uint16_t)0x0001)
#define GPIO_PIN_1                    ((uint16_t)0x0002)
#define GPIO_PIN_2                    ((uint16_t)0x0004)
#define GPIO_PIN_3                    ((uint16_t)0x0008)
#define GPIO_PIN_4                    ((uint16_t)0x0010)
#define GPIO_PIN_5                    ((uint16_t)0x0020)
#define GPIO_PIN_6                    ((uint16_t)0x0040)
#define GPIO_PIN_7                    ((uint16_t)0x0080)
#define GPIO_PIN_8                    ((uint16_t)0x0100)
#define GPIO_PIN_9                    ((uint16_t)0x0200)
#define GPIO_PIN_10                ((uint16_t)0x0400)
#define GPIO_PIN_11                    ((uint16_t)0x0800)
#define GPIO_PIN_12                    ((uint16_t)0x1000)
#define GPIO_PIN_13                    ((uint16_t)0x2000)
#define GPIO_PIN_14                    ((uint16_t)0x4000)
#define GPIO_PIN_15                    ((uint16_t)0x8000)
#define GPIO_PIN_All                ((uint16_t)0xFFFF)


typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFHR;
    volatile uint32_t BRR;
    volatile uint32_t ASCR;
} GPIO_Struct;

#define GPIOA ((GPIO_Struct *) GPIOA_BASE_START)
#define GPIOB ((GPIO_Struct *) GPIOB_BASE_START)
#define GPIOC ((GPIO_Struct *) GPIOC_BASE_START)
#define GPIOD ((GPIO_Struct *) GPIOD_BASE_START)
#define GPIOE ((GPIO_Struct *) GPIOE_BASE_START)
#define GPIOF ((GPIO_Struct *) GPIOF_BASE_START)
#define GPIOG ((GPIO_Struct *) GPIOG_BASE_START)
#define GPIOH ((GPIO_Struct *) GPIOH_BASE_START)

#define ALTERNATE_FUNCTION 2
#define OUTPUT 1
#define INPUT  0

void GPIO_INIT(GPIO_Struct *GPIO_STRUCT, uint16_t PINS, uint8_t PIN_MODE);

void GPIO_WRITE(GPIO_Struct *GPIO_STRUCT, uint16_t PINS, uint8_t PIN_SET_MODE);

uint8_t GPIO_READ(GPIO_Struct *GPIO_STRUCT, uint16_t PIN_NUMBER);

