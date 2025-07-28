//
// Created by CHRIT on 25-7-6.
//

#ifndef __TRACK_H
#define __TRACK_H

#include "stm32g4xx.h"

void Track(int8_t *speed_L, int8_t *speed_R);

#define L2 HAL_GPIO_ReadPin(L2_GPIO_Port, L2_Pin)
#define L1 HAL_GPIO_ReadPin(L1_GPIO_Port, L1_Pin)
#define M HAL_GPIO_ReadPin(M_GPIO_Port, M_Pin)
#define R1 HAL_GPIO_ReadPin(R1_GPIO_Port, R1_Pin)
#define R2 HAL_GPIO_ReadPin(R2_GPIO_Port, R2_Pin)

#endif //__TRACK_H
