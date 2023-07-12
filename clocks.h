#pragma once

#include <stdio.h>
#include <stdint.h>
#include "const_values.h"

#define CLOCK_GPIO_A                ((uint16_t)0x0001)
#define CLOCK_GPIO_B                ((uint16_t)0x0002)
#define CLOCK_GPIO_C                ((uint16_t)0x0004)
#define CLOCK_GPIO_D                ((uint16_t)0x0008)
#define CLOCK_GPIO_E                ((uint16_t)0x0010)
#define CLOCK_GPIO_F                ((uint16_t)0x0020)
#define CLOCK_GPIO_G                ((uint16_t)0x0040)
#define CLOCK_GPIO_H                ((uint16_t)0x0080)


#define CLOCK_BASE            0x40001000UL
#define AHB1_BASE        (PERP_START + 0x00020000UL)
#define RCC_BASE            (0x40021000)
#define PWR_BASE            (PERP_START + 0x7000UL)


typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t RESERVED0;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t RESERVED1[3];
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
} TIM_6;

typedef struct {
    volatile uint32_t UN_USED;
    volatile uint32_t CR2;
} PWR_t;

typedef struct {
    volatile uint32_t UN_USED[19];
    volatile uint32_t CLOCK;
    volatile uint32_t xx[2];
    volatile uint32_t APB1ENR1;
    volatile uint32_t APB1ENR2;
} CLOCKS_t;

#define PER_CLOCKS ((CLOCKS_t*) RCC_BASE)
#define PWR ((PWR_t*) PWR_BASE)

void Turn_CLOCK_RCC();

void Turn_On_Clock_VDD();

void Turn_On_GPIO_CLOCK(uint16_t GPIO_CLOCK);


