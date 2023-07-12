#include <stdio.h>
#include <stdint.h>
#include "clocks.h"
#include "gpio.h"
#include "const_values.h"
#include "uart_functions.h"

#define Fclk 4000000

#define BUFFER_SIZE 11
struct CYCLIC_BUFFER {
    char BUFFER[BUFFER_SIZE];
    int HEAD;
    int TAIL;
};

int push(struct CYCLIC_BUFFER *buffer, char variable);
int pop_all(struct CYCLIC_BUFFER *buffer);
int pop_5(struct CYCLIC_BUFFER *buffer);
void pop(struct CYCLIC_BUFFER *buffer);



int main(void) {

    Turn_CLOCK_RCC();
    Turn_On_Clock_VDD();

    init_UART();

    struct CYCLIC_BUFFER buff = {};
    buff.HEAD = 0;
    buff.TAIL = 0;
    while (1) {
        char res = read();
        if ((res >= 'A' && res <= 'Z') || (res >= 'a' && res <= 'z')) {
            push(&buff, res);
        } else if (res == '1') {
            pop_all(&buff);
        } else if (res == '2') {
            pop_5(&buff);
        }else if (res == '3'){
            pop(&buff);
        }
    }
}

int pop_5(struct CYCLIC_BUFFER *buffer) {
    for (int i = 0; i < 5; i++) {
        pop(buffer);
    }
}

int pop_all(struct CYCLIC_BUFFER *buffer) {
    for (int i = buffer->TAIL; i != buffer->HEAD; i = (i + 1) % BUFFER_SIZE) {
        send(buffer->BUFFER[buffer->TAIL]);
        buffer->TAIL = (buffer->TAIL + 1) % BUFFER_SIZE;
    }
    return 0;
}

int push(struct CYCLIC_BUFFER *buffer, char variable) {
    if ((buffer->HEAD + 1) % (BUFFER_SIZE) == buffer->TAIL) {
        buffer->BUFFER[buffer->HEAD] = variable;
        buffer->HEAD = (buffer->HEAD + 1) % BUFFER_SIZE;
        buffer->TAIL = (buffer->TAIL + 1) % BUFFER_SIZE;
        return 1;
    }
    buffer->BUFFER[buffer->HEAD] = variable;
    buffer->HEAD = (buffer->HEAD + 1) % BUFFER_SIZE;

    return 1;
}
void pop(struct CYCLIC_BUFFER *buffer) {
    if (buffer->TAIL != buffer->HEAD) {
        int x = buffer->TAIL;
        buffer->TAIL = (buffer->TAIL + 1) % BUFFER_SIZE;
        send(buffer->BUFFER[x]);
    }else{
        send(' ');
    }
}
