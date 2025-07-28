//
// Created by CHRIT on 25-7-17.
//

#include "Voice.h"
#include "MOTOR.h"

void Voice_Control(int8_t *speed_L, int8_t *speed_R, uint8_t *VoiceData, uint8_t *mode)
{

    if (*VoiceData == 1) //直线加速
    {
        *speed_L = 20;
        *speed_R = 20;
        Motor(*speed_L, *speed_R);
        *VoiceData = 0;
    }
    else if (*VoiceData == 2) //直线减速
    {
        *speed_L = -20;
        *speed_R = -20;
        Motor(*speed_L, *speed_R);
        *VoiceData = 0;
    }
    else if (*VoiceData == 3) //左转
    {
        *speed_L = 1;
        *speed_R = 60;
        Motor(*speed_L, *speed_R);
        *VoiceData = 0;
    }
    else if (*VoiceData == 4) //右转
    {
        *speed_L = 60;
        *speed_R = 1;
        Motor(*speed_L, *speed_R);
        *VoiceData = 0;
    }
    else if (*VoiceData == 5) //停止
    {
        *speed_L = 0;
        *speed_R = 0;
        Motor(*speed_L, *speed_R);
        *VoiceData = 0;
    }
    else if (*VoiceData == 6) //切换模态为循迹
    {
        *mode = 1;
        *speed_L = 20;
        *speed_R = 20;
        Motor(*speed_L, *speed_R); // 初始直行状态
        *VoiceData = 0;
    }
    else if (*VoiceData == 7) //切换模态为自由探索
    {
        *mode = 2;
        *speed_L = 20;
        *speed_R = 20;
        Motor(*speed_L, *speed_R); // 初始直行状态
        *VoiceData = 0;
    }
    else if (*VoiceData == 8) //切换模态为遥控
    {
        *mode = 0;
        *speed_L = 0;
        *speed_R = 0;
        Motor(*speed_L, *speed_R); // 初始直行状态
        *VoiceData = 0;
    }
}