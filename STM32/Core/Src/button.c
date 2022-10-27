/*
 * button.c
 *
 *  Created on: Oct 12, 2022
 *      Author: khuon
 */


#include "button.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int KeyReg4 = NORMAL_STATE;
int KeyReg5 = NORMAL_STATE;
int KeyReg6 = NORMAL_STATE;
int KeyReg7 = NORMAL_STATE;

int TimeOutForKeyPress1 =  500;
int TimeOutForKeyPress2 =  500;
int button1_flag = 0;
int button2_flag = 0;


void subKeyProcessButton1(){
	//TODO
	//HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	button1_flag = 1;
}

void subKeyProcessButton2(){
	//TODO
	//HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	button2_flag = 1;
}

void getKeyInput1(){
  KeyReg2 = KeyReg1;
  KeyReg1 = KeyReg0;
  KeyReg0 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
    if (KeyReg2 != KeyReg3){
      KeyReg3 = KeyReg2;

      if (KeyReg3 == PRESSED_STATE){
        TimeOutForKeyPress1 = 500;
        subKeyProcessButton1();
      }
    }else{
       TimeOutForKeyPress1 --;
        if (TimeOutForKeyPress1 == 0){
          KeyReg3 = NORMAL_STATE;
        }
    }
  }
}

void getKeyInput2(){
  KeyReg6 = KeyReg5;
  KeyReg5 = KeyReg4;
  KeyReg4 = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
  if ((KeyReg5 == KeyReg4) && (KeyReg5 == KeyReg6)){
    if (KeyReg6 != KeyReg7){
      KeyReg7 = KeyReg6;

      if (KeyReg7 == PRESSED_STATE){
        TimeOutForKeyPress2 = 500;
        subKeyProcessButton2();
      }
    }else{
       TimeOutForKeyPress2 --;
        if (TimeOutForKeyPress2 == 0){
          KeyReg7 = NORMAL_STATE;
        }
    }
  }
}
