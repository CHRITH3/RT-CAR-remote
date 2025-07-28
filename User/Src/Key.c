//
// Created by CHRIT on 25-7-7.
//

#include "KEY.h"
#include "LED.h"
#include "main.h"

uint8_t KEY_VALUE= 0; //定义按键变量

uint8_t Key_GetNum(void) //GPIO_PinState 是 HAL 库中定义的一个数据类型，表示 GPIO 引脚的状态，可以是 GPIO_PIN_RESET 或 GPIO_PIN_SET
{


    if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)==GPIO_PIN_RESET)
    {
        HAL_Delay(20); //消抖
        while (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)==GPIO_PIN_RESET); //等待松开
        HAL_Delay(20); //消抖
        KEY_VALUE=1;
     //   LED_Turn();
    }
    if (HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin)==GPIO_PIN_RESET)
    {
        HAL_Delay(20); //消抖
        while (HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin)==GPIO_PIN_RESET); //等待松开
        HAL_Delay(20); //消抖
        KEY_VALUE=2;
      //  LED_Turn();
    }
    return KEY_VALUE;
}
