/*
 * led_dislay.h
 *
 *  Created on: Oct 17, 2025
 *      Author: ADMIN
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#define RED_STATUS 1
#define YELLOW_STATUS 2
#define GREEN_STATUS 3

#include "main.h"
#include "timer.h"

extern int red_time;
extern int yellow_time;
extern int green_time;

void display_segment_1(int number);
void display_segment_2(int number);

void led_init();
void led();

#endif /* INC_LED_DISPLAY_H_ */
