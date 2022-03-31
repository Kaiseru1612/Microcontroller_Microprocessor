/*
 * Led_7seg_display.c
 *
 *  Created on: Sep 17, 2021
 *      Author: LAPTOP MSI
 */
#include "main.h"
#include "Led_7seg_display.h"


static uint8_t senvensegmentConvertion[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
uint8_t sevensegmentbuffer[NUMBER_OF_SEGMENT]={0,0,0,0};

void updateClockBuffer (uint8_t min, uint8_t hour){
	if (min < 10){
		sevensegmentbuffer[2]=0;
		sevensegmentbuffer[3]=min;
	}
	else {
		sevensegmentbuffer[3]=min%10;
		min = min/10;
		sevensegmentbuffer[2]=min%10;
	}

	if (hour < 10){
		sevensegmentbuffer[0]=0;
		sevensegmentbuffer[1]=hour;
	}
	else {
		sevensegmentbuffer[0]=1;
		sevensegmentbuffer[1]=hour%10;
	}
}

void update7SEG (int index ) {
 switch ( index ) {
 	 case 0:
 		 seven_segment_led_driver(0);
 		 // Display the first 7 SEG with led_buffer [0]
 		 break ;
 	 case 1:
 		 seven_segment_led_driver(1);
 		 // Display the second 7 SEG with led_buffer [1]
 		 break ;
 	 case 2:
 		 seven_segment_led_driver(2);
 		 // Display the third 7 SEG with led_buffer [2]
 		 break ;
 	 case 3:
 		 seven_segment_led_driver(3);
 		 // Display the forth 7 SEG with led_buffer [3]
 		 break ;
 	 default :
 		 break ;
 }
}
void seven_segment_led_driver(int index){
	uint8_t tmp1 = senvensegmentConvertion[sevensegmentbuffer[index]];
	if (tmp1 & 0x01) {
		HAL_GPIO_WritePin(seven_segment_1_a_GPIO_Port, seven_segment_1_a_Pin, RESET);
	}
	else {
		HAL_GPIO_WritePin(seven_segment_1_a_GPIO_Port, seven_segment_1_a_Pin, SET);
	}
	if (tmp1 & 0x02) {
		HAL_GPIO_WritePin(seven_segment_1_a_GPIO_Port, seven_segment_1_b_Pin, RESET);
	}
	else {
		HAL_GPIO_WritePin(seven_segment_1_a_GPIO_Port, seven_segment_1_b_Pin, SET);
	}
	if (tmp1 & 0x04) {
		HAL_GPIO_WritePin(seven_segment_1_a_GPIO_Port, seven_segment_1_c_Pin, RESET);
	}
	else {
		HAL_GPIO_WritePin(seven_segment_1_a_GPIO_Port, seven_segment_1_c_Pin, SET);
	}
	if (tmp1 & 0x08) {
		HAL_GPIO_WritePin(seven_segment_1_a_GPIO_Port, seven_segment_1_d_Pin, RESET);
	}
	else {
		HAL_GPIO_WritePin(seven_segment_1_a_GPIO_Port, seven_segment_1_d_Pin, SET);
	}
	if (tmp1 & 0x10) {
		HAL_GPIO_WritePin(seven_segment_1_a_GPIO_Port, seven_segment_1_e_Pin, RESET);
	}
	else {
		HAL_GPIO_WritePin(seven_segment_1_a_GPIO_Port, seven_segment_1_e_Pin, SET);
	}
	if (tmp1 & 0x20) {
		HAL_GPIO_WritePin(seven_segment_1_a_GPIO_Port, seven_segment_1_f_Pin, RESET);
	}
	else {
		HAL_GPIO_WritePin(seven_segment_1_a_GPIO_Port, seven_segment_1_f_Pin, SET);
	}
	if (tmp1 & 0x40) {
		HAL_GPIO_WritePin(seven_segment_1_a_GPIO_Port, seven_segment_1_g_Pin, RESET);
	}
	else {
		HAL_GPIO_WritePin(seven_segment_1_a_GPIO_Port, seven_segment_1_g_Pin, SET);
	}
}
