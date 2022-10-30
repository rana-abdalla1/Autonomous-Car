/*
 * Servo_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_SERVO_SERVO_INTERFACE_H_
#define HAL_SERVO_SERVO_INTERFACE_H_

#include "STD.h"
#include "Timer_Interface.h"


void H_Servo_Void_ServoInit(void);
void H_Servo_Void_ServoSetAngel(s16);
void H_Servo_Void_ServoSetStart(void);
void H_Servo_Void_ServoSetStop(void);
void H_Servo_Void_ServoForward(void);
void H_Servo_Void_ServoRight(void);
void H_Servo_Void_ServoLeft(void);

#endif /* HAL_SERVO_SERVO_INTERFACE_H_ */
