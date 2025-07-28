//
// Created by CHRIT on 25-7-17.
//

#include "auto.h"
#include "main.h"
#include "MOTOR.h"
#include "OLED.h"
#include "Serial.h"
#include "SR04.h"
#include "Servo.h"

void Auto_Init()
{
    Run(20);
    uint16_t a = measure_distance_cm(); //判断前方距离
    OLED_ShowNum(38, 4, a, 3, 12); //显示前方距离

    //前方有障碍物
    if(a<15){
        Stop();

        Servo_SetAngle(0); //向右看
        HAL_Delay(1000); //看1秒
        uint16_t b= measure_distance_cm(); //判断右侧距离
        OLED_ShowNum(38, 4, b, 3, 12); //显示右侧距离

        //右侧没有障碍物
        if(b>15){
            Servo_SetAngle(90); //向前看
            HAL_Delay(1000);
            Right_Turn(); //右转
            Run(30);
        }

        //右侧有障碍物
        else {
            Servo_SetAngle(180); //向左看
            HAL_Delay(1000);
            uint16_t c= measure_distance_cm(); //判断左侧距离
            OLED_ShowNum(38, 4, c, 3, 12); //显示左侧距离

            //左侧没有障碍物
            if(c>15){
                Servo_SetAngle(90); //向前看
                HAL_Delay(1000);
                Left_Turn(); //左转
                Run(30);
            }

            //左侧有障碍物
            else
            {
                Servo_SetAngle(90); //向前看
                Back(); //倒车
                HAL_Delay(2000); //倒车2秒
                Stop(); //停止
            }
        }
    }
    HAL_Delay(100);
}
