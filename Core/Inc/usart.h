/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
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
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern UART_HandleTypeDef huart4;

extern UART_HandleTypeDef huart1;

extern UART_HandleTypeDef huart2;

extern UART_HandleTypeDef huart3;

/* USER CODE BEGIN Private defines */
  //变量声明
  #define BUFFER_SIZE  128
  extern volatile uint8_t rxLen_uart1;
  extern volatile uint8_t rxLen_uart2;
  extern volatile uint8_t rxLen_uart4;
  extern uint8_t rx_buffer_uart1[BUFFER_SIZE];
  extern uint8_t rx_buffer_uart2[BUFFER_SIZE];
  extern uint8_t rx_buffer_uart4[BUFFER_SIZE];

  //函数声明
  extern void (*OnRecvEnd_uart1)(uint8_t* data, uint16_t len);
  extern void (*OnRecvEnd_uart2)(uint8_t* data, uint16_t len);
  extern void (*OnRecvEnd_uart4)(uint8_t* data, uint16_t len);
  void Uart1_SetRxCpltCallBack(void (*xerc)(uint8_t*, uint16_t));
  void Uart2_SetRxCpltCallBack(void (*xerc)(uint8_t*, uint16_t));
  void Uart4_SetRxCpltCallBack(void (*xerc)(uint8_t*, uint16_t));

/* USER CODE END Private defines */

void MX_UART4_Init(void);
void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);
void MX_USART3_UART_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

