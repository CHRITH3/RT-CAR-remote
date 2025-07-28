/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

  extern uint8_t scan;

  extern uint8_t RxData; //蓝牙数据
  extern uint8_t flag_bt; //蓝牙接收标志位

  extern int8_t speed_L; //左轮速度
  extern int8_t speed_R;

  extern uint8_t center_x;
  extern uint8_t center_y;

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
#define B2_Pin GPIO_PIN_13
#define B2_GPIO_Port GPIOC
#define B2_EXTI_IRQn EXTI15_10_IRQn
#define B3_Pin GPIO_PIN_14
#define B3_GPIO_Port GPIOC
#define B3_EXTI_IRQn EXTI15_10_IRQn
#define B4_Pin GPIO_PIN_15
#define B4_GPIO_Port GPIOC
#define B4_EXTI_IRQn EXTI15_10_IRQn
#define RCC_OSC_IN_Pin GPIO_PIN_0
#define RCC_OSC_IN_GPIO_Port GPIOF
#define RCC_OSC_OUT_Pin GPIO_PIN_1
#define RCC_OSC_OUT_GPIO_Port GPIOF
#define PWM1_Pin GPIO_PIN_0
#define PWM1_GPIO_Port GPIOC
#define PWM2_Pin GPIO_PIN_1
#define PWM2_GPIO_Port GPIOC
#define PWM3_Pin GPIO_PIN_2
#define PWM3_GPIO_Port GPIOC
#define PWM4_Pin GPIO_PIN_3
#define PWM4_GPIO_Port GPIOC
#define BIN1_Pin GPIO_PIN_0
#define BIN1_GPIO_Port GPIOA
#define AIN2_Pin GPIO_PIN_1
#define AIN2_GPIO_Port GPIOA
#define CIN2_Pin GPIO_PIN_2
#define CIN2_GPIO_Port GPIOA
#define CIN1_Pin GPIO_PIN_3
#define CIN1_GPIO_Port GPIOA
#define DAC1_Pin GPIO_PIN_4
#define DAC1_GPIO_Port GPIOA
#define DAC2_Pin GPIO_PIN_5
#define DAC2_GPIO_Port GPIOA
#define OLED_SCL_Pin GPIO_PIN_4
#define OLED_SCL_GPIO_Port GPIOC
#define CAM_RX1_Pin GPIO_PIN_5
#define CAM_RX1_GPIO_Port GPIOC
#define AIN1_Pin GPIO_PIN_0
#define AIN1_GPIO_Port GPIOB
#define R3_Pin GPIO_PIN_1
#define R3_GPIO_Port GPIOB
#define R2_Pin GPIO_PIN_2
#define R2_GPIO_Port GPIOB
#define DEBUG_TX3_Pin GPIO_PIN_10
#define DEBUG_TX3_GPIO_Port GPIOB
#define Servo_Pin GPIO_PIN_11
#define Servo_GPIO_Port GPIOB
#define R1_Pin GPIO_PIN_12
#define R1_GPIO_Port GPIOB
#define DHT11_Pin GPIO_PIN_13
#define DHT11_GPIO_Port GPIOB
#define ECHO_Pin GPIO_PIN_14
#define ECHO_GPIO_Port GPIOB
#define TRIG_Pin GPIO_PIN_15
#define TRIG_GPIO_Port GPIOB
#define L2_Pin GPIO_PIN_6
#define L2_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_7
#define LED1_GPIO_Port GPIOC
#define L3_Pin GPIO_PIN_8
#define L3_GPIO_Port GPIOC
#define BUZZ_Pin GPIO_PIN_9
#define BUZZ_GPIO_Port GPIOC
#define OLED_SDA_Pin GPIO_PIN_8
#define OLED_SDA_GPIO_Port GPIOA
#define CAM_TX1_Pin GPIO_PIN_9
#define CAM_TX1_GPIO_Port GPIOA
#define DIN1_Pin GPIO_PIN_10
#define DIN1_GPIO_Port GPIOA
#define M_Pin GPIO_PIN_11
#define M_GPIO_Port GPIOA
#define L1_Pin GPIO_PIN_12
#define L1_GPIO_Port GPIOA
#define T_SWDIO_Pin GPIO_PIN_13
#define T_SWDIO_GPIO_Port GPIOA
#define T_SWCLK_Pin GPIO_PIN_14
#define T_SWCLK_GPIO_Port GPIOA
#define MPU6050_SCL_Pin GPIO_PIN_15
#define MPU6050_SCL_GPIO_Port GPIOA
#define Unused_TX4_Pin GPIO_PIN_10
#define Unused_TX4_GPIO_Port GPIOC
#define ASR01_RX4_Pin GPIO_PIN_11
#define ASR01_RX4_GPIO_Port GPIOC
#define B1_Pin GPIO_PIN_12
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define BIN2_Pin GPIO_PIN_2
#define BIN2_GPIO_Port GPIOD
#define BT_TX2_Pin GPIO_PIN_3
#define BT_TX2_GPIO_Port GPIOB
#define BT_RX2_Pin GPIO_PIN_4
#define BT_RX2_GPIO_Port GPIOB
#define DIN2_Pin GPIO_PIN_5
#define DIN2_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_6
#define LED2_GPIO_Port GPIOB
#define MPU6050_SDA_Pin GPIO_PIN_7
#define MPU6050_SDA_GPIO_Port GPIOB
#define DEBUG_RX3_Pin GPIO_PIN_8
#define DEBUG_RX3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
