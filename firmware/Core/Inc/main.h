/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32c0xx_hal.h"

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
#define SERVO_Pin GPIO_PIN_1
#define SERVO_GPIO_Port GPIOA
#define VOLT_U_Pin GPIO_PIN_2
#define VOLT_U_GPIO_Port GPIOA
#define VOLT_V_Pin GPIO_PIN_3
#define VOLT_V_GPIO_Port GPIOA
#define VOLT_W_Pin GPIO_PIN_4
#define VOLT_W_GPIO_Port GPIOA
#define CUR_U_Pin GPIO_PIN_5
#define CUR_U_GPIO_Port GPIOA
#define CUR_V_Pin GPIO_PIN_6
#define CUR_V_GPIO_Port GPIOA
#define VOLT_WA7_Pin GPIO_PIN_7
#define VOLT_WA7_GPIO_Port GPIOA
#define ENABLE_Pin GPIO_PIN_2
#define ENABLE_GPIO_Port GPIOB
#define W_H_Pin GPIO_PIN_8
#define W_H_GPIO_Port GPIOA
#define V_L_Pin GPIO_PIN_9
#define V_L_GPIO_Port GPIOA
#define V_H_Pin GPIO_PIN_6
#define V_H_GPIO_Port GPIOC
#define U_L_Pin GPIO_PIN_10
#define U_L_GPIO_Port GPIOA
#define U_H_Pin GPIO_PIN_11
#define U_H_GPIO_Port GPIOA
#define CS_Pin GPIO_PIN_6
#define CS_GPIO_Port GPIOB
#define EN_Pin GPIO_PIN_7
#define EN_GPIO_Port GPIOB
#define FAULT_Pin GPIO_PIN_8
#define FAULT_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
