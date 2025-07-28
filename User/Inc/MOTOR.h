//
// Created by CHRIT on 25-7-9.
//

#ifndef MOTOR_H
#define MOTOR_H

#include "main.h"
//启动PWM输出
void Motor_Start();
//用speed参数设置占空比
void MotorA_Speed(int8_t speed);
void MotorB_Speed(int8_t speed);
void MotorC_Speed(int8_t speed);
void MotorD_Speed(int8_t speed);


void Run(int8_t speed);
void Right_Turn();
void Left_Turn();
void Back();
void Stop();

//左右轮分别给参数
void Motor(int8_t L, int8_t R);

//蓝牙控制左右轮速度
void Motor_BlueTooth(int8_t *speed_L, int8_t *speed_R, uint8_t *RxData, uint8_t *mode);

#endif //MOTOR_H
