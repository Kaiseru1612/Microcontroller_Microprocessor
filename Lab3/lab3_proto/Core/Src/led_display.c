/*
 * led_display.c
 *
 *  Created on: Oct 4, 2021
 *      Author: Admin
 */


#include "main.h"
#include "led_display.h"
#include "display7SEG.h"





int tmpRed=RED, tmpYell=YELLOW, tmpGreen=GREEN;
static int timer0_counter = 0;
int timer0_flag = 0;
static int timerMode_counter = 0;
int timerMode_flag = 0;


void setTimerMode ( int duration ){
	timerMode_counter = duration / TIMER_CYCLE ;
	timerMode_flag = 0;
}
void timerMode_run(){
	if( timerMode_counter > 0){
	timerMode_counter --;
	if( timerMode_counter == 0) timerMode_flag = 1;
	}
}
void setTimerNormal ( int duration ){
	timer0_counter = duration / TIMER_CYCLE ;
	timer0_flag = 0;
}
void timerNormal_run(){
	if( timer0_counter > 0){
	timer0_counter --;
	if( timer0_counter == 0) timer0_flag = 1;
	}
}

enum Traffic_State {RED1_GREEN2, RED1_YELL2, RED2_YELL1, RED2_GREEN1} traffic_State;

enum Traffic_State traffic_State = RED1_GREEN2;

void init_led(int red_time, int yellow_time, int green_time){
	tmpRed = red_time;
	tmpYell = yellow_time;
	tmpGreen = green_time;
}
void clear_all(){
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, RESET);
}
void display_led_normal(int red_time, int yellow_time, int green_time){
	for (int var = 0;  var < DISPLAY_TIME;  var++) {
		switch(traffic_State){
	case RED1_GREEN2:
		HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, GPIO_PIN_RESET);
		if (tmpGreen==0 || tmpRed == 0){
			traffic_State = RED1_YELL2;
		}
		else {
			display7SEG(LED_SEGMENT1, tmpRed/10);
			HAL_Delay(LED_TIME);
			turn_off_7seg(LED_SEGMENT1);
			display7SEG(LED_SEGMENT2, tmpRed%10);
			HAL_Delay(LED_TIME);
			turn_off_7seg(LED_SEGMENT2);
			display7SEG(LED_SEGMENT3, tmpGreen/10);
			HAL_Delay(LED_TIME);
			turn_off_7seg(LED_SEGMENT3);
			display7SEG(LED_SEGMENT4, tmpGreen%10);
			HAL_Delay(LED_TIME);
			turn_off_7seg(LED_SEGMENT4);
			if(timer0_flag==1){
			  tmpGreen--;
			  tmpRed--;
			  setTimerNormal(TIMER_TIME);
			}
		}
		break;
	case RED1_YELL2:
		  HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, GPIO_PIN_SET);

		  HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, GPIO_PIN_SET);
		  if (tmpYell==0 || tmpRed == 0){
			  init_led(red_time, yellow_time, green_time);
			  traffic_State = RED2_GREEN1;
		  }
		  else {
			  display7SEG(LED_SEGMENT1, tmpRed/10);
			  HAL_Delay(LED_TIME);
			  turn_off_7seg(LED_SEGMENT1);
			  display7SEG(LED_SEGMENT2, tmpRed%10);
			  HAL_Delay(LED_TIME);
			  turn_off_7seg(LED_SEGMENT2);
			  display7SEG(LED_SEGMENT3, tmpYell/10);
			  HAL_Delay(LED_TIME);
			  turn_off_7seg(LED_SEGMENT3);
			  display7SEG(LED_SEGMENT4, tmpYell%10);
			  HAL_Delay(LED_TIME);
			  turn_off_7seg(LED_SEGMENT4);
			  if(timer0_flag==1){
				  tmpYell--;
				  tmpRed--;
				  setTimerNormal(TIMER_TIME);
			  }
		  	  }
		break;
	case RED2_GREEN1:
		  	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, GPIO_PIN_SET);
		  	HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, GPIO_PIN_SET);
		  	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, GPIO_PIN_RESET);

		  	HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, GPIO_PIN_RESET);
		  	HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_SET);
		  	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, GPIO_PIN_SET);
		if (tmpGreen==0 || tmpRed == 0){
			  traffic_State = RED2_YELL1;
		}
		else {
			display7SEG(LED_SEGMENT3, tmpRed/10);
			HAL_Delay(LED_TIME);
			turn_off_7seg(LED_SEGMENT3);
			display7SEG(LED_SEGMENT4, tmpRed%10);
			HAL_Delay(LED_TIME);
			turn_off_7seg(LED_SEGMENT4);
			display7SEG(LED_SEGMENT1, tmpGreen/10);
			HAL_Delay(LED_TIME);
			turn_off_7seg(LED_SEGMENT1);
			display7SEG(LED_SEGMENT2, tmpGreen%10);
			HAL_Delay(LED_TIME);
			turn_off_7seg(LED_SEGMENT2);
			if(timer0_flag==1){
				tmpGreen--;
				tmpRed--;
				setTimerNormal(TIMER_TIME);
			}
		}
		break;
	case RED2_YELL1:
		HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, GPIO_PIN_SET);
		if (tmpYell==0 || tmpRed == 0){
			init_led(red_time, yellow_time, green_time);
			traffic_State = RED1_GREEN2;
		}
		else {
			display7SEG(LED_SEGMENT3, tmpRed/10);
			HAL_Delay(LED_TIME);
			turn_off_7seg(LED_SEGMENT3);
			display7SEG(LED_SEGMENT4, tmpRed%10);
			HAL_Delay(LED_TIME);
			turn_off_7seg(LED_SEGMENT4);
			display7SEG(LED_SEGMENT1, tmpYell/10);
			HAL_Delay(LED_TIME);
			turn_off_7seg(LED_SEGMENT1);
			display7SEG(LED_SEGMENT2, tmpYell%10);
			HAL_Delay(LED_TIME);
			turn_off_7seg(LED_SEGMENT2);
			if(timer0_flag==1){
  				tmpYell--;
  				tmpRed--;
  				setTimerNormal(TIMER_TIME);
			}
			}
			break;
}
	}

}

void display_mode(int mode, int red_time, int yellow_time, int green_time)
{
	if	(timerMode_flag){
		switch (mode){
				case 1:
					  HAL_GPIO_TogglePin(LED1_RED_GPIO_Port, LED1_RED_Pin);
					  HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, GPIO_PIN_SET);
					  HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, GPIO_PIN_SET);

					  HAL_GPIO_TogglePin(LED2_RED_GPIO_Port, LED2_RED_Pin);
					  HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_SET);
					  HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, GPIO_PIN_SET);
					break;
				case 2:
					  HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, GPIO_PIN_SET);
					  HAL_GPIO_TogglePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin);
					  HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, GPIO_PIN_SET);

					  HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, GPIO_PIN_SET);
					  HAL_GPIO_TogglePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin);
					  HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, GPIO_PIN_SET);
					break;
				case 3:
					  HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, GPIO_PIN_SET);
					  HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, GPIO_PIN_SET);
					  HAL_GPIO_TogglePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin);

					  HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, GPIO_PIN_SET);
					  HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_SET);
					  HAL_GPIO_TogglePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin);
					break;
			}
		setTimerMode(ModeBlink);
	}
	  for(int i=0;i<DISPLAY_TIME;i++){
		  display7SEG(LED_SEGMENT1, 0);
		  HAL_Delay(1);
		  turn_off_7seg(LED_SEGMENT1);

		  display7SEG(LED_SEGMENT2, mode);
		  HAL_Delay(1);
		  turn_off_7seg(LED_SEGMENT2);

		  switch (mode){
		  case 1:
			  display7SEG(LED_SEGMENT3, red_time/10);
			  HAL_Delay(1);
			  turn_off_7seg(LED_SEGMENT3);

			  display7SEG(LED_SEGMENT4, red_time%10);
			  HAL_Delay(1);
			  turn_off_7seg(LED_SEGMENT4);
			  break;
		  case 2:
			  display7SEG(LED_SEGMENT3, yellow_time/10);
			  HAL_Delay(1);
			  turn_off_7seg(LED_SEGMENT3);

			  display7SEG(LED_SEGMENT4, yellow_time%10);
			  HAL_Delay(1);
			  turn_off_7seg(LED_SEGMENT4);
			  break;
		  case 3:
			  display7SEG(LED_SEGMENT3, green_time/10);
			  HAL_Delay(1);
			  turn_off_7seg(LED_SEGMENT3);

			  display7SEG(LED_SEGMENT4, green_time%10);
			  HAL_Delay(1);
			  turn_off_7seg(LED_SEGMENT4);
			  break;
		  default:
			  display7SEG(LED_SEGMENT3, 0);
			  HAL_Delay(1);
			  turn_off_7seg(LED_SEGMENT3);

			  display7SEG(LED_SEGMENT4, 0);
			  HAL_Delay(1);
			  turn_off_7seg(LED_SEGMENT4);
			  break;
		  }
	  }
}
