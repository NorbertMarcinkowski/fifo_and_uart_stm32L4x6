#pragma once

#include <stdio.h>
#include <stdint.h>
#include "const_values.h"
#include "gpio.h"
#include "clocks.h"

#define LPUART_BASE        (PERP_START + 0x8000uL)

typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t CR3;
    volatile uint32_t BRR;
    volatile uint32_t reserved[2];
    volatile uint32_t RQR;
    volatile uint32_t ISR;
    volatile uint32_t ICR;
    volatile uint32_t RDR;
    volatile uint32_t TDR;
} LPUART;

#define MY_LPUART ((LPUART*) LPUART_BASE)

void init_UART();

void turn_af_function_for_uart(int pin);

char cast(char buff);

char read();

void send(char buff);