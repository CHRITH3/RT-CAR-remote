//
// Created by CHRIT on 25-7-9.
//

#ifndef SERIAL_H
#define SERIAL_H

#include "main.h"

//数组声明可以不要数组长度
extern  uint8_t Serial_RxFlag; //接收标志位，置1表示接收到完整数据
extern  uint8_t Serial_RxBuffer;
extern  uint8_t Serial_TxBuffer[];

void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *array, uint16_t length);
void Serial_SendString(char *string);
uint32_t Serial_Pow(uint32_t base, uint32_t exp);
void Serial_SendNumber(uint32_t number, uint8_t length);
void Serial_SendPacket(void); //发送数据包
uint8_t Serial_GetFlag(void); //获取接收标志位，并清除该标志位

#endif //SERIAL_H
