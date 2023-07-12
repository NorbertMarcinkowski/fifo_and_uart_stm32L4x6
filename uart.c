/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* USER CODE END Header */

#include <stdio.h>
#include <stdint.h>
#include "const_values.h"
#include "uart_functions.h"
#include "clocks.h"


#define DELAY 1
#define JOY_DELAY 20
#define COUNT_DELAY 1000
#define SHOW_DELAY 4
#define Fclk 4000000


int main(void)
{
  	Turn_CLOCK_RCC();
  	Turn_On_Clock_VDD();
  	init_UART();

  	while(1){
		send(cast(read()));
  	}
}
