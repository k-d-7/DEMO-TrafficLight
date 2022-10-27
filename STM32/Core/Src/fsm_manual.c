/*
 * fsm_manual.c
 *
 *  Created on: Oct 12, 2022
 *      Author: khuon
 */

#include "fsm_manual.h"

void fsm_manual_run() {
	switch (status) {
		case MAN_RED:
			//TODO
			HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, SET);
			HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, RESET);
			if(timer1_flag == 1) {
				timer1_flag = 0;
				status = AUTO_RED;
				setTimer1(300);
			}
			if (button1_flag == 1) {
				button1_flag = 0;
				status = MAN_GREEN;
				setTimer1(1000);
			}
			if (button2_flag == 1) {
				button2_flag = 0;
				status = MAN_YELLOW;
				setTimer1(1000);
			}
			break;
		case MAN_GREEN:
			HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, RESET);
			HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, SET);
			HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, RESET);
			if(timer1_flag == 1) {
				timer1_flag = 0;
				status = AUTO_GREEN;
				setTimer1(300);
			}
			if (button1_flag == 1) {
				button1_flag = 0;
				status = MAN_YELLOW;
				setTimer1(1000);
			}
			if (button2_flag == 1) {
				button2_flag = 0;
				status = MAN_RED;
				setTimer1(1000);
			}
			break;
		case MAN_YELLOW:
			HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, RESET);
			HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, SET);
			if(timer1_flag == 1) {
				timer1_flag = 0;
				status = AUTO_YELLOW;
				setTimer1(200);
			}
			if (button1_flag == 1) {
				button1_flag = 0;
				status = MAN_RED;
				setTimer1(1000);
			}
			if (button2_flag == 1) {
				button2_flag = 0;
				status = MAN_GREEN;
				setTimer1(1000);
			}
			break;
		default:
			break;
	}
}
