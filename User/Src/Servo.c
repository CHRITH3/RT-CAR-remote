//
// Created by CHRIT on 25-7-9.
//

#include "Servo.h"
#include "main.h"
#include "OLED.h"
#include "tim.h"
#include "stdint.h"

void Servo_Init()
{
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, (90/180)*2000 + 500);
}

void Servo_SetAngle(float angle)
{
    if (angle > 180 || angle < 0)
    {
        OLED_ShowString(98, 4, "ERROR", 12);
    }
    else
    {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, (angle/180)*2000 + 500);
    }
}

void Servo_BlueTooth(float *angle, uint8_t *RxData)
{

    if (*RxData == 1) //直线加速
    {
        *angle = 0;
        Servo_SetAngle(*angle);
        *RxData = 0;
    }
    else if (*RxData == 2) //直线减速
    {
        *angle = 45;
        Servo_SetAngle(*angle);
        *RxData = 0;
    }
    else if (*RxData == 3) //左转
    {
        *angle = 90;
        Servo_SetAngle(*angle);
        *RxData = 0;
    }
    else if (*RxData == 4) //右转
    {
        *angle = 135;
        Servo_SetAngle(*angle);
        *RxData = 0;
    }
    else if (*RxData == 5) //停止
    {
        *angle = 180;
        Servo_SetAngle(*angle);
        *RxData = 0;
    }

}