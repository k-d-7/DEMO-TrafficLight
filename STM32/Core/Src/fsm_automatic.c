#include "fsm_automatic.h"

void fsm_automatic_run() {
	switch (status) {
	case INIT:
		status = AUTO_RED;
		setTimer1(500);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(FIRST_GPIO_Port, FIRST_Pin, SET);
		HAL_GPIO_WritePin(SECOND_GPIO_Port, SECOND_Pin, RESET);
		if (timer1_flag == 1) {
			status = AUTO_GREEN;
			setTimer1(300);
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(FIRST_GPIO_Port, FIRST_Pin, RESET);
		HAL_GPIO_WritePin(SECOND_GPIO_Port, SECOND_Pin, SET);
		if (timer1_flag == 1) {
			status = AUTO_YELLOW;
			setTimer1(200);
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(FIRST_GPIO_Port, FIRST_Pin, SET);
		HAL_GPIO_WritePin(SECOND_GPIO_Port, SECOND_Pin, SET);
		if (timer1_flag == 1) {
			status = AUTO_RED;
			setTimer1(500);
		}
		break;
	default:
		break;
	}
}
