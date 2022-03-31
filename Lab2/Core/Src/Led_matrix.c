/*
 * Led_matrix.c
 *
 *  Created on: Sep 26, 2021
 *      Author: LAPTOP MSI
 */

#include "main.h"

#define MAX_FRAME	7

int frame=0;
//uint8_t disp_col[8] =  {0xff,0xc0,0x8b,0x1b,0x1b,0x8b,0xc0,0xff};
//uint8_t disp_col[8] =  {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
uint8_t disp_col[8] =  {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
uint8_t disp_row[8][8] = {	{0xff,0x03,0xd9,0xdc,0xdc,0xd9,0x03,0xff},
							{0xff,0xff,0x03,0xd9,0xdc,0xdc,0xd9,0x03},
							{0x03,0xff,0xff,0x03,0xd9,0xdc,0xdc,0xd9},
							{0xd9,0x03,0xff,0xff,0x03,0xd9,0xdc,0xdc},
							{0xdc,0xd9,0x03,0xff,0xff,0x03,0xd9,0xdc},
							{0xdc,0xdc,0xd9,0x03,0xff,0xff,0x03,0xd9},
							{0xd9,0xdc,0xdc,0xd9,0x03,0xff,0xff,0x03},
							{0x03,0xd9,0xdc,0xdc,0xd9,0x03,0xff,0xff}};

void updateAnimation (void){
	frame++;
	if (frame>MAX_FRAME) {
		frame = 0;
	}
}
void updateLEDMatrix (int index ){
switch ( index ){
	case 0:
		  displayCol(index);
		  displayRow(index);
		break ;
	case 1:
		  displayCol(index);
		  displayRow(index);
		break ;
	case 2:
		  displayCol(index);
		  displayRow(index);
		break ;
	case 3:
		  displayCol(index);
		  displayRow(index);
		break ;
	case 4:
		  displayCol(index);
		  displayRow(index);
		break ;
	case 5:
		  displayCol(index);
		  displayRow(index);
		break ;
	case 6:
		  displayCol(index);
		  displayRow(index);
		break ;
	case 7:
		  displayCol(index);
		  displayRow(index);
		break ;
	default :
		break ;
	}
}

void displayCol (int col){
	uint8_t disp_hex_col = disp_col[col];
	uint8_t  disp_bit;

	disp_bit = disp_hex_col & 0x01;
	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin , disp_bit);

	disp_bit = (disp_hex_col>>1) & 0x01;
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin , disp_bit);

	disp_bit = (disp_hex_col>>2) & 0x01;
	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin , disp_bit);

	disp_bit = (disp_hex_col>>3) & 0x01;
	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin , disp_bit);

	disp_bit = (disp_hex_col>>4) & 0x01;
	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin , disp_bit);

	disp_bit = (disp_hex_col>>5) & 0x01;
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin , disp_bit);

	disp_bit = (disp_hex_col>>6) & 0x01;
	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin , disp_bit);

	disp_bit = (disp_hex_col>>7) & 0x01;
	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin , disp_bit);
}

void displayRow (int row){
	uint8_t  disp_hex_row = disp_row[frame][row];
	uint8_t  disp_bit;

	disp_bit = disp_hex_row & 0x01;
	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin , disp_bit);

	disp_bit = (disp_hex_row>>1) & 0x01;
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin , disp_bit);

	disp_bit = (disp_hex_row>>2) & 0x01;
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin , disp_bit);

	disp_bit = (disp_hex_row>>3) & 0x01;
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin , disp_bit);

	disp_bit = (disp_hex_row>>4) & 0x01;
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin , disp_bit);

	disp_bit = (disp_hex_row>>5) & 0x01;
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin , disp_bit);

	disp_bit = (disp_hex_row>>6) & 0x01;
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin , disp_bit);

	disp_bit = (disp_hex_row>>7) & 0x01;
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin , disp_bit);
}
void clearAll(void){
	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, RESET);
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, RESET);
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, RESET);
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, RESET);
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, RESET);
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, RESET);
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, RESET);
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, RESET);

	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
}
void setupMatrix(void){
	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);

	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
}
