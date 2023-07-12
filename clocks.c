#include "clocks.h"

void Turn_CLOCK_RCC() {
    PER_CLOCKS->APB1ENR1 |= 1UL << 28;
}

void Turn_On_Clock_VDD() {
    PWR->CR2 |= 1UL << 9;
}

void Turn_On_GPIO_CLOCK(uint16_t GPIO_CLOCK) {
    PER_CLOCKS->CLOCK |= GPIO_CLOCK;
}