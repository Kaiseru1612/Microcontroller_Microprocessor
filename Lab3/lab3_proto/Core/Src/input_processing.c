/*
 * input_processing.c
 *
 *  Created on: Oct 4, 2021
 *      Author: Admin
 */


#include "main.h"
#include "input_reading.h"
#include "display7SEG.h"
#include "led_display.h"
static int red_time = 5;
static int yellow_time = 2;
static int green_time = 3;
static int tmp_time=0;

  enum ButtonState { MODE_0 , MODE_1, EDIT_MODE1, MODE_2, EDIT_MODE2, MODE_3, EDIT_MODE3} buttonState;
  enum ButtonState buttonState = MODE_0;

void fsm_for_input_processing (){

	switch(buttonState)
		  {
		  case MODE_0:
			  clear_all();
			  display_led_normal(red_time, yellow_time, green_time);
			  if(is_button_pressed(0))
			  {
			  	buttonState = MODE_1;
			  }
			  else{
			  	buttonState = MODE_0;
			  }
			 break;
			 /////////////////////////////////////////
		  case MODE_1:
			  clear_all();
			  display_mode(1, red_time, yellow_time, green_time);
			  tmp_time = red_time;
			  if(is_button_pressed(0))
			  {
			  	buttonState = MODE_2;
			  }
			  if(is_button_pressed(1)){
			  	if (red_time < 100) {
			  		red_time++;
			  	}
			  	buttonState = EDIT_MODE1;
			  }
			 break;
		  case EDIT_MODE1:
			  clear_all();
			  display_mode(1, red_time, yellow_time, green_time);
			  if(is_button_pressed(0))
			  {
				red_time = tmp_time;
			  	buttonState = MODE_1;
			  }
			  if(is_button_pressed(1)){
			  		if (red_time<100) {
			  			red_time++;
			  		}
			  }
			  if(is_button_pressed(2)){
				  	 display_mode(0, red_time, yellow_time, green_time);
				  	buttonState = MODE_1;
			  }
			  break;
				 /////////////////////////////////////////
		  case MODE_2:
			  clear_all();
			  display_mode(2, red_time, yellow_time, green_time);
			  tmp_time = yellow_time;
			  if(is_button_pressed(0))
			  {
			  	buttonState = MODE_3;
			  }
			  if(is_button_pressed(1))
			  {
				if (yellow_time < 100) {
					yellow_time++;
				}
			  	buttonState = EDIT_MODE2;
			  }
			 break;
		  case EDIT_MODE2:
			  clear_all();
			  display_mode(2, red_time, yellow_time, green_time);
			  if(is_button_pressed(0))
			  {
				yellow_time = tmp_time;
			  	buttonState = MODE_2;
			  }
			  if(is_button_pressed(1)){
			  		if (yellow_time < 100) {
			  			yellow_time++;
			  		}
			  }
			  if(is_button_pressed(2)){
				  	 display_mode(0, red_time, yellow_time, green_time);
				  	buttonState = MODE_2;
			  }
			  break;
				 /////////////////////////////////////////
		  case MODE_3:
			  clear_all();
			  display_mode(3, red_time, yellow_time, green_time);
			  tmp_time = green_time;
			  if(is_button_pressed(0))
			  {
				red_time = yellow_time + green_time;
				init_led(red_time, yellow_time, green_time);
			  	buttonState = MODE_0;
			  }
			  if(is_button_pressed(1)){
			  		if (green_time < 100){
			  			green_time++;
			  		}
			  		buttonState = EDIT_MODE3;
			  }
			 break;
		  case EDIT_MODE3:
			  clear_all();
			  display_mode(3, red_time, yellow_time, green_time);
			  if(is_button_pressed(0))
			  {
				green_time = tmp_time;
			  	buttonState = MODE_2;
			  }
			  if(is_button_pressed(1)){
			  		if (green_time < 100) {
			  			green_time++;
			  		}
			  }
			  if(is_button_pressed(2)){
				  	 display_mode(0, red_time, yellow_time, green_time);
				  	buttonState = MODE_3;
			  }
			  break;
		  }

}




