#include "fsm_automatic.h"

void fsm_automatic_run() {
	switch (status) {
	case INIT:
		status = AUTO_RED;
		setTimer1(300);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, SET);
		HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, RESET);

		if (timer1_flag == 1) {
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			status = AUTO_YELLOW;
			setTimer1(200);
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
	case AUTO_GREEN:
		HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, RESET);

		if (timer1_flag == 1) {
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			status = AUTO_RED;
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
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, SET);

		if (timer1_flag == 1) {
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			status = AUTO_GREEN;
			setTimer1(300);
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
