/*
 * led_display.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Admin
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#define LED_TIME	2
#define TIMER_TIME	1000
#define ModeBlink	500
#define RED 		5
#define YELLOW		2
#define GREEN		3
#define LED_SEGMENT1	1
#define LED_SEGMENT2	2
#define LED_SEGMENT3	3
#define LED_SEGMENT4	4
#define DISPLAY_TIME	20

void display_led_normal(int red_time, int yellow_time, int green_time);
void init_led(int red_time, int yellow_time, int green_time);
void clear_all();
void setTimerNormal ( int duration);
void timerNormal_run();
void display_mode(int mode, int red_time, int yellow_time, int green_time);
void setTimerMode ( int duration );
#endif /* INC_LED_DISPLAY_H_ */
