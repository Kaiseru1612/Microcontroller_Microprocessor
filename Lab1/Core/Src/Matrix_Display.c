/*
 * Matrix_Display.c
 *
 *  Created on: Sep 18, 2021
 *      Author: LAPTOP MSI
 */
#include "main.h"
#include "Matrix_Display.h"

//uint8_t row_sweep[7] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf,0x7f};
//
//uint8_t col_decode[][12] ={
//		0xff,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,	//1
//		0xff,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,0xff,	//2
//		0xff,0xff,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,	//3
//		0xff,0xff,0xff,0xdff,0xdf,0xff,0xff,0xff,0xff,	//4
//		0xff,0xff,0xff,0xdff,0xff,0xef,0xff,0xff,0xff,	//5
//		0xff,0xff,0xff,0xdff,0xff,0xf7,0xff,0xff,0xff,
//		0xff,0xff,0xff,0xdff,0xff,0xfb,0xff,0xff,0xff,
//		0xff,0xff,0xff,0xdff,0xfd,0xff,0xff,0xff,0xff,
//		0xff,0xff,0xff,0xdfd,0xff,0xff,0xff,0xff,0xff,
//		0xff,0xff,0xfd,0xdff,0xff,0xff,0xff,0xff,0xff,
//		0xff,0xfb,0xff,0xdff,0xff,0xff,0xff,0xff,0xff,
//		0xff,0xf7,0xff,0xdff,0xff,0xff,0xff,0xff,0xff,
//};
//
//void matrix_display_driver(void){
//
//}

void displayClock(int second, int minute, int hour){
	  setNumberOnClock(second/5);
	  HAL_Delay(5);
	  clearNumberOnClock(second/5);
	  setNumberOnClock(minute/5);
	  HAL_Delay(5);
	  clearNumberOnClock(minute/5);
	  setNumberOnClock(hour);
	  HAL_Delay(5);
	  clearNumberOnClock(hour);
}
void testLed (void){
	// First row
	HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
	HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
	HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
	HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
	HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);
	HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);

	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, RESET);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, RESET);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin,RESET);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, RESET);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, RESET);

	clearAllClock();
	//Second row
	HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
	HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
	HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
	HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
	HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);
	HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);

	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, RESET);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, RESET);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin,RESET);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, RESET);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, RESET);

	clearAllClock();
	//Third row
	HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
	HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
	HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
	HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
	HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);
	HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);

	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, RESET);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, RESET);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin,RESET);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, RESET);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, RESET);

	clearAllClock();
	//Fourth row
	HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
	HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
	HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
	HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
	HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);
	HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);

	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, RESET);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, RESET);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin,RESET);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, RESET);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, RESET);

	clearAllClock();
	//fifth row
	HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
	HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
	HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
	HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
	HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);
	HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);

	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, RESET);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, RESET);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin,RESET);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, RESET);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, RESET);

	clearAllClock();
	//sixth row
	HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
	HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
	HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
	HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
	HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
	HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);

	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, RESET);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, RESET);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin,RESET);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, RESET);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, RESET);

	clearAllClock();
	//seventh row
	HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
	HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
	HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
	HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
	HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
	HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);

	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, RESET);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, RESET);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin,RESET);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, SET);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, RESET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, RESET);
	clearAllClock();
}
void clearAllClock(void){
	HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin, RESET);
	HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, RESET);
	HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin,RESET);
	HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, RESET);
	HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, RESET);
	HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, RESET);
	HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, RESET);
	HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, RESET);
	HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, RESET);
	HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, RESET);
	HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, RESET);
	HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, RESET);
}
void setNumberOnClock(int num){
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin,SET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin,SET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin,SET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);
			break;
		case 3:
			HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin,SET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);
			break;
		case 4:
			HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin,SET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);
			break;
		case 5:
			HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin,SET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);
			break;
		case 6:
			HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin,SET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);
			break;
		case 7:
			HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin,SET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin,SET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);
			break;
		case 9:
			HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin,SET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);
			break;
		case 10:
			HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin,SET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, SET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);
			break;
		case 11:
			HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin,SET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, SET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, SET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, SET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, SET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, SET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, SET);
			break;
		default:
			break;
	}
}
void clearNumberOnClock(int num){
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin,RESET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, RESET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, RESET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, RESET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, RESET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, RESET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin,RESET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, RESET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, RESET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, RESET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, RESET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, RESET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin,RESET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, RESET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, RESET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, RESET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, RESET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, RESET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin,RESET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, RESET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, RESET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, RESET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, RESET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, RESET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin,RESET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, RESET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, RESET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, RESET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, RESET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, RESET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin,RESET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, RESET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, RESET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, RESET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, RESET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, RESET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin,RESET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, RESET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, RESET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, RESET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, RESET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, RESET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(ROW_0_GPIO_Port, ROW_0_Pin,RESET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, RESET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, RESET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, RESET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, RESET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, RESET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin,RESET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, RESET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, RESET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, RESET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, RESET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, RESET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin,RESET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, RESET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, RESET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, RESET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, RESET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, RESET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, RESET);
			break;
		case 10:
			HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin,RESET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, RESET);
			HAL_GPIO_WritePin(COL_2_GPIO_Port, COL_2_Pin, RESET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, RESET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, RESET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, RESET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, RESET);
			break;
		case 11:
			HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin,RESET);
			HAL_GPIO_WritePin(COL_0_GPIO_Port, COL_0_Pin, RESET);
			HAL_GPIO_WritePin(COL_1_GPIO_Port, COL_1_Pin, RESET);
			HAL_GPIO_WritePin(COL_3_GPIO_Port, COL_3_Pin, RESET);
			HAL_GPIO_WritePin(COL_4_GPIO_Port, COL_4_Pin, RESET);
			HAL_GPIO_WritePin(COL_5_GPIO_Port, COL_5_Pin, RESET);
			HAL_GPIO_WritePin(COL_6_GPIO_Port, COL_6_Pin, RESET);
			break;
		default:
			break;
	}
}

