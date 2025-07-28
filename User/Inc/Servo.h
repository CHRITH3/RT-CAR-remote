//
// Created by CHRIT on 25-7-9.
//

#ifndef SERVO_H
#define SERVO_H

#include "stdint.h"

void Servo_Init();
void Servo_SetAngle(float angle);
void Servo_BlueTooth(float *angle, uint8_t *RxData);

#endif //SERVO_H

