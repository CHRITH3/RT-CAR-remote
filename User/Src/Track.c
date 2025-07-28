//
// Created by CHRIT on 25-7-6.
//

#include "Track.h"
#include "main.h"
#include "stdint.h"
#include "Motor.h"
#include "dac.h"
#include "tim.h"

void Track(int8_t *speed_L, int8_t *speed_R)
{

    if (L2 == 1) //大左转
    {
            *speed_L = -20;
            *speed_R = 60;
            Motor(*speed_L,*speed_R);
    }
    else if (L1 == 1) //小左转
    {
            *speed_L = 10;
            *speed_R = 50;
            Motor(*speed_L,*speed_R);
    }
    else if (M == 1) //直行
    {
            *speed_L = 20;
            *speed_R = 20;
            Motor(*speed_L,*speed_R);
    }
    else if (R1 == 1) //小右转
    {
            *speed_L = 50;
            *speed_R = 10;
            Motor(*speed_L,*speed_R);
    }
    else if (R2 == 1) //大右转
    {
            *speed_L = 60;
            *speed_R = -20;
            Motor(*speed_L,*speed_R);
    }
    else
    {
            *speed_L = 20;
            *speed_R = 20;
            Motor(*speed_L,*speed_R);
    }
}
