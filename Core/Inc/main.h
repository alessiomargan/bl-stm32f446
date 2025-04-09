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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern CRC_HandleTypeDef hcrc;
extern SPI_HandleTypeDef hspi3;
extern TIM_HandleTypeDef htim7;
extern UART_HandleTypeDef huart2;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
/*
#define DBG_1_ON HAL_GPIO_WritePin(DBG_1_GPIO_Port, DBG_1_Pin, GPIO_PIN_SET)
#define DBG_1_OFF HAL_GPIO_WritePin(DBG_1_GPIO_Port, DBG_1_Pin, GPIO_PIN_RESET)
#define DBG_1_TGL HAL_GPIO_TogglePin(DBG_1_GPIO_Port, DBG_1_Pin)

#define DBG_2_ON HAL_GPIO_WritePin(DBG_2_GPIO_Port, DBG_2_Pin, GPIO_PIN_SET)
#define DBG_2_OFF HAL_GPIO_WritePin(DBG_2_GPIO_Port, DBG_2_Pin, GPIO_PIN_RESET)
#define DBG_2_TGL HAL_GPIO_TogglePin(DBG_2_GPIO_Port, DBG_2_Pin)

#define TOGLLE_GRN HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin)
*/
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ecat_spi hspi3
#define printf_uart huart2
#define BTN_1_Pin GPIO_PIN_13
#define BTN_1_GPIO_Port GPIOC
#define DBG_1_Pin GPIO_PIN_2
#define DBG_1_GPIO_Port GPIOC
#define DBG_2_Pin GPIO_PIN_3
#define DBG_2_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LED_1_Pin GPIO_PIN_5
#define LED_1_GPIO_Port GPIOA
#define ECAT_IRQ_Pin GPIO_PIN_8
#define ECAT_IRQ_GPIO_Port GPIOC
#define ECAT_IRQ_EXTI_IRQn EXTI9_5_IRQn
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define ECAT_CS_Pin GPIO_PIN_2
#define ECAT_CS_GPIO_Port GPIOD
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
