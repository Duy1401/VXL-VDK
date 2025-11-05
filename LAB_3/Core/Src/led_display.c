/*
 * led_display.c
 *
 *  Created on: Oct 17, 2025
 *      Author: ADMIN
 */


#include "led_display.h"

int status1 = RED_STATUS;
int status2 = GREEN_STATUS;

int red_time = 5;
int yellow_time = 2;
int green_time = 3;

int time1, time2;

void display_segment_1(int number){
	switch(number){
		case 0:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_6, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2|GPIO_PIN_5, GPIO_PIN_SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
			break;
	}
}

void display_segment_2(int number){
	switch(number){
		case 0:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10|GPIO_PIN_13, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9|GPIO_PIN_12, GPIO_PIN_SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
			break;
	}
}

void led_init(){
	time1 = red_time;
	time2 = green_time;
}

void led(){
	if(counter_led <= 0){
		time1--;
		time2--;
	}
	switch (status1) {
		case RED_STATUS:
			if(counter_led_traffic <= 0){
				if(statement == 1){
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
					display_segment_1(time1 / 10);
				}
				else{
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
					display_segment_1(time1 % 10);
				}
			}
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_SET);
			if(time1 <= 0){
				status1 = GREEN_STATUS;
				time1 = green_time;
			}
			break;
		case GREEN_STATUS:
			if(counter_led_traffic <= 0){
				if(statement == 1){
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
					display_segment_1(time1 / 10);
				}
				else{
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
					display_segment_1(time1 % 10);
				}
			}
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_SET);
			if(time1 <= 0){
				status1 = YELLOW_STATUS;
				time1 = yellow_time;
			}
			break;
		case YELLOW_STATUS:
			if(counter_led_traffic <= 0){
				if(statement == 1){
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
					display_segment_1(time1 / 10);
				}
				else{
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
					display_segment_1(time1 % 10);
				}
			}
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_6, GPIO_PIN_SET);
			if(time1 <= 0){
				status1 = RED_STATUS;
				time1 = red_time;
			}
			break;
		default:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_SET);
			break;
	}

	switch (status2) {
		case RED_STATUS:
			if(counter_led_traffic <= 0){
				if(statement == 1){
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
					display_segment_2(time2 / 10);
				}
				else{
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
					display_segment_2(time2 % 10);
				}
			}
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_SET);
			if(time2 <= 0){
				status2 = GREEN_STATUS;
				time2 = green_time;
			}
			break;
		case GREEN_STATUS:
			if(counter_led_traffic <= 0){
				if(statement == 1){
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
					display_segment_2(time2 / 10);
				}
				else{
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
					display_segment_2(time2 % 10);
				}
			}
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_8, GPIO_PIN_SET);
			if(time2 <= 0){
				status2 = YELLOW_STATUS;
				time2 = yellow_time;
			}
			break;
		case YELLOW_STATUS:
			if(counter_led_traffic <= 0){
				if(statement == 1){
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
					display_segment_2(time2 / 10);
				}
				else{
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
					display_segment_2(time2 % 10);
				}
			}
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_9, GPIO_PIN_SET);
			if(time2 <= 0){
				status2 = RED_STATUS;
				time2 = red_time;
			}
			break;
		default:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_SET);
			break;
	}
}


