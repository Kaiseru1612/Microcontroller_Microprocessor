/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ROW_0_Pin GPIO_PIN_4
#define ROW_0_GPIO_Port GPIOA
#define ROW_1_Pin GPIO_PIN_5
#define ROW_1_GPIO_Port GPIOA
#define ROW_2_Pin GPIO_PIN_6
#define ROW_2_GPIO_Port GPIOA
#define ROW_3_Pin GPIO_PIN_7
#define ROW_3_GPIO_Port GPIOA
#define ROW_4_Pin GPIO_PIN_8
#define ROW_4_GPIO_Port GPIOA
#define COL_6_Pin GPIO_PIN_9
#define COL_6_GPIO_Port GPIOA
#define COL_5_Pin GPIO_PIN_10
#define COL_5_GPIO_Port GPIOA
#define COL_4_Pin GPIO_PIN_11
#define COL_4_GPIO_Port GPIOA
#define COL_3_Pin GPIO_PIN_12
#define COL_3_GPIO_Port GPIOA
#define COL_2_Pin GPIO_PIN_13
#define COL_2_GPIO_Port GPIOA
#define COL_1_Pin GPIO_PIN_14
#define COL_1_GPIO_Port GPIOA
#define COL_0_Pin GPIO_PIN_15
#define COL_0_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */
#define MAX_SECOND	60
#define MAX_MINUTE	60
#define MAX_HOUR	12
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
