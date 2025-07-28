//
// Created by CHRIT on 25-7-9.
//

#include "Serial.h"

#include <stdint.h>

#include "stm32g4xx_hal_uart.h"
#include "usart.h"

 uint8_t Serial_RxFlag; //接收标志位，置1表示接收到完整数据。回调函数放在了main.c中，因此需要声明为全局变量。
 uint8_t Serial_RxBuffer = 0; //接收缓冲区，最大接收长度为1字节
 uint8_t Serial_TxBuffer[4]; //发送缓冲区，最大发送长度为4字节

void Serial_SendByte(uint8_t Data)
{
    HAL_UART_Transmit(&huart3, &Data, 1, HAL_MAX_DELAY);
    //函数的超时时间为HAL_MAX_DELAY，意味着如果数据没有在传输过程中发生错误，则函数将一直等待，直到数据发送完成。
}

void Serial_SendArray(uint8_t *Array, uint16_t Size)
{
    uint16_t i = 0;
    for (i = 0; i < Size; i++)
    {
        Serial_SendByte(Array[i]);
    }
}

void Serial_SendString(char *String)
{
    uint8_t i = 0;
    for (i = 0; String[i] != '\0'; i++)
    {
        Serial_SendByte(String[i]);
    }
}

uint32_t Serial_Pow(uint32_t base, uint32_t exp)
{
    uint32_t result = 1;
    while (exp --)
    {
        result *= base;
    }
    return result;
}

void Serial_SendNumber(uint32_t number, uint8_t length)
{
    uint8_t i = 0;
    for (i = 0; i < length; i++)
    {
        //依次取出数字的每一位，并加上ASCII码的偏移值'0'
        Serial_SendByte( number / Serial_Pow(10, length - i - 1)% 10 + '0');

    }
}

void Serial_SendPacket(void)
{
    Serial_SendByte(0xFF);
    Serial_SendArray(Serial_TxBuffer, 4);
    Serial_SendByte(0xFE);
}

uint8_t Serial_GetFlag(void) //获取接收标志位，并清除该标志位
{
    if (Serial_RxFlag == 1)
    {
        Serial_RxFlag = 0;
        return 1; //注意不要return Serial_RxFlag，因为已经被置0
    }
    return 0;
}