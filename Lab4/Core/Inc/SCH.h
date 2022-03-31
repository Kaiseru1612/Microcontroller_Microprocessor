#ifndef INC_SCH_H_
#define INC_SCH_H_

#include "main.h"

typedef struct sTask{

	// Pointer to task
	void (*pTask) (void);

	// Delay (ticks) until the function will ( next ) be run
	uint32_t Delay;

	// Interval ( ticks ) between subsequent runs
	uint32_t Period;

	// Incremented ( by scheduler ) when task is due to execute
	uint8_t RunMe;

	// This is a hint to solve the question below
	uint32_t TaskID;

}sTask;

#define SCH_MAX_TASKS 6
#define NO_TASK_ID 0
sTask SCH_tasks_G[SCH_MAX_TASKS];




void SCH_Update(void);
void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef* htim );
void SCH_Add_Task( void (* pFunction) () , unsigned int DELAY, unsigned int PERIOD);
unsigned char SCH_Delete_Task( const int TASK_INDEX);
void SCH_Dispatch_Tasks(void);
void SCH_Init(void);

#endif /* INC_SCH_H_ */
