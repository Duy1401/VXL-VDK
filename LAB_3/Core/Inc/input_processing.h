/*
 * input_processing.h
 *
 *  Created on: Oct 17, 2025
 *      Author: ADMIN
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

#include "main.h"
#include "input_reading.h"
#include "led_display.h"

extern int mode;
extern uint8_t button1Flag;
extern int duration;
void fsm_for_input_processing(void);
#endif /* INC_INPUT_PROCESSING_H_ */
