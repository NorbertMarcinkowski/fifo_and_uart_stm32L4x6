#include "gpio.h"

void GPIO_INIT(GPIO_Struct *GPIO_STRUCT, uint16_t PINS, uint8_t PIN_MODE) {
    if (PIN_MODE == OUTPUT) {   //set output mode
        for (uint16_t i = 0; i < (uint16_t) 16; ++i) {
            if ((PINS & (uint16_t) 1 << i) == (uint16_t) 1 << i) {
                GPIO_STRUCT->MODER |= (1U << i * 2);//set first bit 1
                GPIO_STRUCT->MODER &= ~(1U << (i * 2 + 1));//set second bit = 0
            }
        }
        GPIO_STRUCT->OTYPER &= ~PINS;//set output push-pull
    }
    if (PIN_MODE == INPUT) {    //set input mode
        for (uint16_t i = 0; i < (uint16_t) 16; ++i) {
            if ((PINS & (uint16_t) 1 << i) == (uint16_t) 1 << i) {
                GPIO_STRUCT->MODER &= ~(1U << i * 2);//set first bit 0
                GPIO_STRUCT->MODER &= ~(1U << (i * 2 + 1));//set second bit = 0
            }
        }
    }
    if (PIN_MODE == ALTERNATE_FUNCTION) {
        for (uint16_t i = 0; i < (uint16_t) 16; ++i) {
            if ((PINS & (uint16_t) 1 << i) == (uint16_t) 1 << i) {
                GPIO_STRUCT->MODER |= (1U << (i * 2 + 1));//set first bit 1
                GPIO_STRUCT->MODER &= ~(1U << (i * 2));//set second bit = 0
            }
        }
    }
}

void GPIO_WRITE(GPIO_Struct *GPIO_STRUCT, uint16_t PINS, uint8_t PIN_SET_MODE) {
    if (PIN_SET_MODE == SET) {
        GPIO_STRUCT->ODR |= PINS;//ustawia 1 pod konkretnym pinem
    }
    if (PIN_SET_MODE == RESET) {
        GPIO_STRUCT->ODR &= ~PINS;//ustawia 0 pod konkretnym pinem
    }
}

uint8_t GPIO_READ(GPIO_Struct *GPIO_STRUCT, uint16_t PIN_NUMBER) {
    if ((GPIO_STRUCT->IDR & PIN_NUMBER) == PIN_NUMBER) {
        return SET;
    }
    return RESET;
}
