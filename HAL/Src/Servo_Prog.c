/*
 * Servo_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "Servo_Interface.h"
#include "Timer_Interface.h"
void H_Servo_Void_ServoInit(void)
{
        M_DIO_Void_SetPinDirection(PB3_PIN,OUTPUT);
	M_Timer_Void_PWMInit(TIMER0_CHANNEL);
	M_Timer_Void_PWMSetFreaquancy(50);
}
void H_Servo_Void_ServoSetAngel(s16 Copy_U8_Angel)
{
	f32 Local_F32_Value = ((Copy_U8_Angel * 5.0 ) / 180.0) + 5.0;
	M_Timer_Void_PWMSetDutyCycle(TIMER0_CHANNEL,Local_F32_Value);
}
void H_Servo_Void_ServoSetStart(void)
{
	M_Timer_Void_PWMStart(TIMER0_CHANNEL);
}
void H_Servo_Void_ServoSetStop(void)
{
M_Timer_Void_PWMStop(TIMER0_CHANNEL);
}
void H_Servo_Void_ServoForward(void)
{
	H_Servo_Void_ServoSetAngel(90);
	H_Servo_Void_ServoSetStart();
}
void H_Servo_Void_ServoLeft(void)
{
	H_Servo_Void_ServoSetAngel(300);
	H_Servo_Void_ServoSetStart();
}
void H_Servo_Void_ServoRight(void)
{
	H_Servo_Void_ServoSetAngel(-90);
	H_Servo_Void_ServoSetStart();
}
