//
// #include "stm32g4xx.h"
// #include "ringbuffer.h"
// #include "serial_protocol.h"
//
// #include <stdio.h>
// #include <string.h>
//
// UART_HandleTypeDef huart2;
// rbuffer_t rbProtocol;
//
// static uint8_t _u8Data = 0x00;
// static uint8_t _aBuffer[256] = {0x00};
// int32_t x , y , width , height ;
// /*
//  * 初始化
//  */
// void protocol_test_init(void)
// {
// 	/*
// 	 * 1. 串口初始化
// 	 */
// 	GPIO_InitTypeDef GPIO_InitStruct = {0};
//
// 	/* Peripheral clock enable */
// 	__HAL_RCC_USART2_CLK_ENABLE();
// 	__HAL_RCC_GPIOA_CLK_ENABLE();
// 	__HAL_RCC_GPIOD_CLK_ENABLE();
// 	/**USART2 GPIO Configuration
// 	PA2     ------> USART2_TX
// 	PA3     ------> USART2_RX
// 	*/
// 	GPIO_InitStruct.Pin   = GPIO_PIN_2;
// 	GPIO_InitStruct.Mode  = GPIO_MODE_AF_PP;
// 	GPIO_InitStruct.Pull  = GPIO_PULLUP;
// 	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
// 	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//
// 	GPIO_InitStruct.Pin  = GPIO_PIN_3;
// 	GPIO_InitStruct.Mode = GPIO_MODE_AF_INPUT;
// 	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//
// 	/* USART2 interrupt Init */
// 	HAL_NVIC_SetPriority(USART2_IRQn, 1, 0);
// 	HAL_NVIC_EnableIRQ(USART2_IRQn);
//
// 	huart2.Instance        = USART2;
// 	huart2.Init.BaudRate   = 115200;
// 	huart2.Init.WordLength = UART_WORDLENGTH_8B;
// 	huart2.Init.StopBits   = UART_STOPBITS_1;
// 	huart2.Init.Parity     = UART_PARITY_NONE;
// 	huart2.Init.Mode       = UART_MODE_TX_RX;
// 	huart2.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
// 	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
//
// 	HAL_UART_Init(&huart2);
// 	HAL_UART_Receive_IT(&huart2, &_u8Data, 1);
//
// 	/*
// 	 * 2. 循环缓冲区初始化
// 	 */
// 	rbuffer_init(&rbProtocol, _aBuffer, sizeof(_aBuffer));
// }
//
// /*
//  * 测试过程
//  */
// void protocol_test_proc(void)
// {
// 	int32_t rc = -1;
// 	uint32_t redundant = 0x00, packet_len = 0;
// 	uint8_t buffer[128] = {0x00};
// 	uint8_t payload[32] = {0x00};
//
//
//
// 	uint32_t len = rbuffer_data_len(&rbProtocol);
// 	if(len == 0){
// 		return;
// 	}
// 	len = (len <= sizeof(buffer)) ? len : sizeof(buffer);
//
//
// 	rbuffer_peek(&rbProtocol, buffer, len);
//
// 	rc = packet_is_valid(buffer, len, &redundant);
// 	if(redundant > 0){
// 		rbuffer_del(&rbProtocol, redundant);
// 	}
//
// 	if(rc >= 0){
// 		packet_decode(&buffer[redundant], len-redundant, payload, sizeof(payload));
// 		memcpy(&x, &payload[0], 4);
// 		memcpy(&y, &payload[4], 4);
// 		memcpy(&width,  &payload[8], 4);
// 		memcpy(&height, &payload[12], 4);
// 		printf("x = %d, y = %d, width = %d height = %d\r\n", x, y, width, height);
//
// 		packet_len = packet_length(&buffer[redundant], len-redundant);
// 		rbuffer_del(&rbProtocol, packet_len);
// 	}
// 	else if((rc == -3) || (rbuffer_status(&rbProtocol) == RB_FULL)){
// 		rbuffer_del(&rbProtocol, len);
// 	}
//
// }
//
// /*
//  * 串口接收完成中断回调
//  */
// void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
// {
// 	if(huart->Instance == USART2){
// 		rbuffer_putchar(&rbProtocol, _u8Data);
//
// 		HAL_UART_Receive_IT(&huart2, &_u8Data, 1);
// 	}
// }
//
