#include <SCH.h>
#include "main.h"

#define MIN_DELAY_DEFAULT 60000;
#define MIN_INDEX_DEFAULT SCH_MAX_TASKS+1

static uint32_t min_delay_time = MIN_DELAY_DEFAULT;
static unsigned char min_delay_index = MIN_INDEX_DEFAULT;

// update

void SCH_Update(void)
{

////////////////////
//// On ////////////
////////////////////
	// NOTE: calculations are in *TICKS* ( not milliseconds )
/*
 * 	unsigned char Index;
	for(Index=0;Index<SCH_MAX_TASKS;Index++)
	{
		// Check if there is a task at this location
		if(SCH_tasks_G[Index].pTask)
		{
			if(SCH_tasks_G[Index].Delay == 0)
			{
				// The task is due to run
				// Increase the RunMe flag
				SCH_tasks_G[Index].RunMe += 1;
				if(SCH_tasks_G[Index].Period)
				{
					// Schedule periodic tasks to run again
					SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
				}
			}
			else{
				// Not yet ready to run : just decrement the delay
				SCH_tasks_G[Index].Delay -= 1;
			}
		}
	}*/
////////////////////
//// O1 ////////////
////////////////////
	if(min_delay_index != SCH_MAX_TASKS+1)
		{
			if(SCH_tasks_G[min_delay_index].Delay == 0)
			{
				SCH_tasks_G[min_delay_index].RunMe += 1;
				if(SCH_tasks_G[min_delay_index].Period)
				{
					// Schedule periodic tasks to run again
					SCH_tasks_G[min_delay_index].Delay = SCH_tasks_G[min_delay_index].Period;
				}

			}

			else{
				SCH_tasks_G[min_delay_index].Delay -= 1;
			}
		}
}

void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef* htim )
{
	SCH_Update();
}

// add task

void SCH_Add_Task( void (*pFunction)() , unsigned int DELAY, unsigned int PERIOD)
{
	unsigned char Index = 0;

	// First find a gap in the array ( if there is one)
	while (( SCH_tasks_G[Index].pTask != 0) && ( Index < SCH_MAX_TASKS) )
	{
		Index++;
	}



	// Have we reached the end of the list ?
/*	if (Index == SCH_MAX_TASKS)
	{
		// Task list is full
		// Set the global error variable
		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		return SCH_MAX_TASKS;
	} */

	// If we’re here , there is a space in the task array
	SCH_tasks_G[Index].pTask = pFunction;
	SCH_tasks_G[Index].Delay = DELAY;
	SCH_tasks_G[Index].Period = PERIOD;
	SCH_tasks_G[Index].RunMe = 0;

	// find min delay task
	if(DELAY < min_delay_time){
		min_delay_time = DELAY;
		min_delay_index = Index;
	}
}

unsigned char SCH_Delete_Task( const int TASK_INDEX)
{
	unsigned char Return_code=0;
	/*if (SCH_tasks_G[TASK_INDEX].pTask == 0)
	{
		Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK
		Return_code = RETURN_ERROR;
	}
	else{
		Return_code = RETURN_NORMAL;
	}*/

	SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
	SCH_tasks_G[TASK_INDEX].Delay = 0;
	SCH_tasks_G[TASK_INDEX].Period = 0;
	SCH_tasks_G[TASK_INDEX].RunMe = 0;

	return Return_code;
}

void SCH_Dispatch_Tasks(void)
{
	////////////////////
	//// On ////////////
	////////////////////

//	unsigned char Index;
//	// Dispatches ( runs ) the next task ( if one is ready )
//	for ( Index = 0; Index < SCH_MAX_TASKS; Index++)
//	{
//		if ( SCH_tasks_G[Index].RunMe > 0)
//		{
//			(*SCH_tasks_G[Index].pTask) () ; // Run the task
//			SCH_tasks_G[ Index ].RunMe -= 1; // Reset / reduce RunMe flag
//
//			// Periodic tasks will automatically run again
//			// − if this is a 'one shot' task , remove it from the array
//			if (SCH_tasks_G[Index].Period == 0)
//			{
//				SCH_Delete_Task(Index);
//			}
//		}
//	}

/*	// Report system status
	SCH_Report_Status();
	// The scheduler enters idle mode at this point
	SCH_Go_To_Sleep(); */

	////////////////////
	//// On ////////////
	////////////////////

	if ( SCH_tasks_G[min_delay_index].RunMe > 0){
			uint32_t temp_min_delay = MIN_DELAY_DEFAULT;
			unsigned char temp_min_index = MIN_INDEX_DEFAULT;
			(*SCH_tasks_G[min_delay_index].pTask) () ; // Run the task
			SCH_tasks_G[ min_delay_index].RunMe -= 1; // Reset / reduce RunMe flag

			// Periodic tasks will automatically run again
				// − if this is a 'one shot' task , remove it from the array
			if (SCH_tasks_G[min_delay_index].Period == 0){
					SCH_Delete_Task(min_delay_index);
			}

			// find the next task that has min delay time
			for(unsigned char i = 0;i<SCH_MAX_TASKS;i++){
				if(SCH_tasks_G[i].pTask)
				{
					if(i!=min_delay_index && SCH_tasks_G[i].Delay < temp_min_delay)
					{
						temp_min_delay = SCH_tasks_G[i].Delay;
						temp_min_index = i;
					}
				}
			}
			min_delay_index = temp_min_index;
			for(unsigned char i = 0;i<SCH_MAX_TASKS;i++){
				if(SCH_tasks_G[i].pTask && i!=min_delay_index){
					SCH_tasks_G[i].Delay -= min_delay_time;
				}

			}
			min_delay_time = SCH_tasks_G[temp_min_index].Delay - min_delay_time;
	}
}


void SCH_Init(void)
{
	unsigned char i;
	for ( i = 0; i<SCH_MAX_TASKS; i++)
	{
		SCH_Delete_Task(i);
	}

//	HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, SET);
//	HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, SET);
//	HAL_GPIO_WritePin(YELL_LED_GPIO_Port, YELL_LED_Pin, SET);
//	HAL_GPIO_WritePin(BLUE_LED_GPIO_Port, BLUE_LED_Pin, SET);
//	HAL_GPIO_WritePin(PURPLE_LED_GPIO_Port, PURPLE_LED_Pin, SET);

/*	Error_code_G = 0;
	Timer_init();
	Watchdog_init(); */
}


