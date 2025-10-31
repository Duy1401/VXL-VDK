/*
 * timer.c
 *
 *  Created on: Oct 17, 2025
 *      Author: ADMIN
 */


#include "timer.h"

#define TIMER_DURATION 10
#define TIMER_COUNTER 500

int counter = TIMER_COUNTER;
int counter_led = 1000;
int a = 0;
int b = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2){
		counter -= TIMER_DURATION;
		counter_led -= TIMER_DURATION;
		button_reading();
		fsm_for_input_processing();
		switch (mode){
			case 1:
				if(button1Flag == 0){
					led();
				}
				break;
			case 2:
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_SET);
				if(counter <= 0){
					HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
					HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
				}
				a = duration/10;
				b = duration%10;
				display_segment_2(a);
				display_segment_3(b);
				break;
			case 3:
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_9, GPIO_PIN_SET);
				if(counter <= 0){
					HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
					HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
				}
				a = duration/10;
				b = duration%10;
				display_segment_2(a);
				display_segment_3(b);
				break;
			case 4:
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7|GPIO_PIN_8, GPIO_PIN_SET);
				if(counter <= 0){
					HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
					HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9);
				}
				a = duration/10;
				b = duration%10;
				display_segment_2(a);
				display_segment_3(b);
				break;
		}
		if(counter <= 0){
			counter = TIMER_COUNTER;
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
		}
		if(counter_led <= 0){
			counter_led = 1000;
		}
	}
}
