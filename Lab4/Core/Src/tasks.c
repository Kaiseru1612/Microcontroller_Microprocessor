#include "main.h"
#include "tasks.h"
void toggleRED(){
	HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
}
void toggleGREEN(){
	HAL_GPIO_TogglePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin);
}
void toggleBLUE(){
	HAL_GPIO_TogglePin(BLUE_LED_GPIO_Port, BLUE_LED_Pin);
}
void toggleYELL(){
	HAL_GPIO_TogglePin(YELL_LED_GPIO_Port, YELL_LED_Pin);
}
void togglePURPLE(){
	HAL_GPIO_TogglePin(PURPLE_LED_GPIO_Port, PURPLE_LED_Pin);
}
