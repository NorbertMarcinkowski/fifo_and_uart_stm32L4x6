#include "uart_functions.h"


void init_UART() {
    Turn_On_GPIO_CLOCK(CLOCK_GPIO_C);
    PER_CLOCKS->APB1ENR2 |= 1 << 0;
    GPIO_INIT(GPIOC, GPIO_PIN_0 | GPIO_PIN_1, ALTERNATE_FUNCTION);

    turn_af_function_for_uart(0);
    turn_af_function_for_uart(1);

    MY_LPUART->CR1 &= ~(1 << 28); // jak wygląda paczka przesyłu danych
    MY_LPUART->CR1 &= ~(1 << 12); // jak wygląda paczka przesyłu danych
    MY_LPUART->BRR |= (256 * Fclk) / 9600; // ustawienie częstotliwości przesyłu danych
    MY_LPUART->CR2 &= ~(1 << 12); // ustawienie jednego bit stopu
    MY_LPUART->CR2 &= ~(1 << 13); // ustawienie jednego bit stopu
    MY_LPUART->CR1 |= 1 << 0; //wlaczenie uarta
}

void turn_af_function_for_uart(int pin) {
    GPIOC->AFRL |= (1 << (pin * 4 + 3));
    GPIOC->AFRL &= ~(1 << (pin * 4 + 2));
    GPIOC->AFRL &= ~(1 << (pin * 4 + 1));
    GPIOC->AFRL &= ~(1 << (pin * 4));
}

void send(char buff) {
    MY_LPUART->CR1 |= 1 << 3;//wlaczenie wysyłania
    MY_LPUART->TDR = buff; // wpisanie danych do wysłania
    while ((MY_LPUART->ISR & (1 << 7)) != (1 << 7)) {}
    MY_LPUART->CR1 &= ~(1 << 3);//wylaczenie wysyłania
}

char read() {
    MY_LPUART->CR1 |= 1 << 2; // wlaczenie zczytwywania
    while ((MY_LPUART->ISR & (1 << 5)) != (1 << 5)) {}
    char rec = MY_LPUART->RDR; // odczytanie danych
    MY_LPUART->CR1 &= ~(1 << 2);// wylaczenie zczytwywania
    return rec;
}

char cast(char buff) {
    if (buff >= 'A' && buff <= 'Z') {
        return buff += ' ';
    }
    if (buff >= 'a' && buff <= 'z') {
        return buff -= ' ';
    }
    return ' ';
}