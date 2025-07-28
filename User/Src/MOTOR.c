//
// Created by CHRIT on 25-7-9.
//

#include "MOTOR.h"

#include "auto.h"
#include "main.h"
#include "OLED.h"
#include "tim.h"
#include "Track.h"

void Motor_Start()
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
}

void MotorA_Speed(int8_t speed)
{
    if (speed > 0 && speed < 101)
    {
        HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_SET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, speed);
    }
    else if (speed > -101)
    {
        HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, -speed);
    }
    else
    {
        HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
    }
}

void MotorB_Speed(int8_t speed)
{
    if (speed > 0 && speed < 101)
    {
        HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(BIN2_GPIO_Port, BIN2_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, speed);
    }
    else if (speed > -101)
    {
        HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(BIN2_GPIO_Port, BIN2_Pin, GPIO_PIN_SET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, -speed);
    }
    else
    {
        HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(BIN2_GPIO_Port, BIN2_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
    }
}

void MotorC_Speed(int8_t speed)
{
    if (speed > 0 && speed < 101)
    {
        HAL_GPIO_WritePin(CIN1_GPIO_Port, CIN1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(CIN2_GPIO_Port, CIN2_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, speed);
    }
    else if (speed > -101)
    {
        HAL_GPIO_WritePin(CIN1_GPIO_Port, CIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(CIN2_GPIO_Port, CIN2_Pin, GPIO_PIN_SET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, -speed);
    }
    else
    {
        HAL_GPIO_WritePin(CIN1_GPIO_Port, CIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(CIN2_GPIO_Port, CIN2_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
    }
}

void MotorD_Speed(int8_t speed)
{
    if (speed > 0 && speed < 101)
    {
        HAL_GPIO_WritePin(DIN1_GPIO_Port, DIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DIN2_GPIO_Port, DIN2_Pin, GPIO_PIN_SET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, speed);
    }
    else if (speed > -101)
    {
        HAL_GPIO_WritePin(DIN1_GPIO_Port, DIN1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DIN2_GPIO_Port, DIN2_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, -speed);
    }
    else
    {
        HAL_GPIO_WritePin(DIN1_GPIO_Port, DIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(DIN2_GPIO_Port, DIN2_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 0);
    }
}


void Run(int8_t speed)
{
    MotorD_Speed(speed);
    MotorA_Speed(speed);
    MotorC_Speed(speed);
    MotorB_Speed(speed);
}

void Right_Turn()
{
    MotorD_Speed(30);
    MotorA_Speed(-30);
    MotorC_Speed(30);
    MotorB_Speed(-30);
    HAL_Delay(1000);
    Stop();
}

void Left_Turn()
{
    MotorD_Speed(-30);
    MotorA_Speed(30);
    MotorC_Speed(-30);
    MotorB_Speed(30);
    HAL_Delay(1000);
    Stop();
}

void Back()
{
    MotorD_Speed(-30);
    MotorA_Speed(-30);
    MotorC_Speed(-30);
    MotorB_Speed(-30);
}

void Stop()
{
    MotorD_Speed(0);
    MotorA_Speed(0);
    MotorC_Speed(0);
    MotorB_Speed(0);
}

//同时控制单边两个轮子
void Motor(int8_t L, int8_t R)
{
    MotorD_Speed(R);
    MotorA_Speed(L);
    MotorC_Speed(R);
    MotorB_Speed(L);
}

//蓝牙遥控，同时控制单边两个轮子
void Motor_BlueTooth(int8_t *speed_L, int8_t *speed_R, uint8_t *RxData, uint8_t *mode)
{

    if (*RxData == 1) //直线加速
    {
        *speed_L = 30;
        *speed_R = 30;
        Motor(*speed_L, *speed_R);
        *RxData = 0;
    }
    else if (*RxData == 2) //直线减速
    {
        *speed_L = -30;
        *speed_R = -30;
        Motor(*speed_L, *speed_R);
        *RxData = 0;
    }
    else if (*RxData == 3) //左转
    {
        *speed_L = 10;
        *speed_R = 70;
        Motor(*speed_L, *speed_R);
        *RxData = 0;
    }
    else if (*RxData == 4) //右转
    {
        *speed_L = 70;
        *speed_R = 10;
        Motor(*speed_L, *speed_R);
        *RxData = 0;
    }
    else if (*RxData == 5) //停止
    {
        *speed_L = 0;
        *speed_R = 0;
        Motor(*speed_L, *speed_R);
        *RxData = 0;
    }
    else if (*RxData == 6) //循迹
    {
        *mode = 1;
        *speed_L = 20;
        *speed_R = 20;
        Motor(*speed_L, *speed_R); // 初始直行状态
        *RxData = 0;
    }
    else if (*RxData == 7) // 自由探索
    {
        *mode = 2;
        *speed_L = 20;
        *speed_R = 20;
        Motor(*speed_L, *speed_R); // 初始直行状态
        *RxData = 0;
    }
    else if (*RxData == 8) // 遥控
    {
        *mode = 0;
        *speed_L = 0;
        *speed_R = 0;
        Motor(*speed_L, *speed_R); // 初始直行状态
        *RxData = 0;
    }

}