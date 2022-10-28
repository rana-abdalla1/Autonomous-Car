/*
 * DCMotor_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include"DIO_Config.h"
#include"DIO_Private.h"
#include "DIO_Interface.h"
#include "DCMotor_Interface.h"
#include"DCMotor_Config.h"
#include "DCMotor_Private.h"
//motor 1 direction pins
#define DC_MOTOR_PIN1     PC5_PIN
#define DC_MOTOR_PIN2     PC6_PIN

//motor 2 direction pins
#define DC_MOTOR_PIN3     PC3_PIN
#define DC_MOTOR_PIN4     PC4_PIN

//motor 1 enable
#define DC_MOTOR1_EN      PC1_PIN

//motor 2 enable
#define DC_MOTOR2_EN      PC0_PIN

// set direction and enable pins of both motors as output
void H_DCMotor_Void_DCMotorInit(void)
{
	M_DIO_Void_SetPinDirection(DC_MOTOR_PIN1,OUTPUT);
	M_DIO_Void_SetPinDirection(DC_MOTOR_PIN2,OUTPUT);
	M_DIO_Void_SetPinDirection(DC_MOTOR_PIN3,OUTPUT);
	M_DIO_Void_SetPinDirection(DC_MOTOR_PIN4,OUTPUT);
    M_DIO_Void_SetPinDirection(DC_MOTOR1_EN,OUTPUT);
    M_DIO_Void_SetPinDirection(DC_MOTOR2_EN,OUTPUT);
}

//rotate right wheel to turn car left
void H_DCMotor_Void_DCMotorTurnLeft(void)
{

	M_DIO_Void_SetPinValue(DC_MOTOR_PIN1,LOW);
	M_DIO_Void_SetPinValue(DC_MOTOR_PIN2,HIGH);


}

//rotate left wheel to turn car right
void H_DCMotor_Void_DCMotorTurnRight(void)
{

	M_DIO_Void_SetPinValue(DC_MOTOR_PIN3,LOW);
	M_DIO_Void_SetPinValue(DC_MOTOR_PIN4,HIGH);


}

//set direction of motor 1
void H_DCMotor_Void_DCMotorSetDirection1(u8 Copy_U8_Direction)
{
switch(Copy_U8_Direction)
{
case ACW:
	M_DIO_Void_SetPinValue(DC_MOTOR_PIN1,LOW);
	M_DIO_Void_SetPinValue(DC_MOTOR_PIN2,HIGH);
	break;
case CW:
	M_DIO_Void_SetPinValue(DC_MOTOR_PIN1,HIGH);
	M_DIO_Void_SetPinValue(DC_MOTOR_PIN2,LOW);
	break;
}

//set direction of motor 2
}

void H_DCMotor_Void_DCMotorSetDirection2(u8 Copy_U8_Direction)
{
switch(Copy_U8_Direction)
{
case ACW:
	M_DIO_Void_SetPinValue(DC_MOTOR_PIN3,LOW);
	M_DIO_Void_SetPinValue(DC_MOTOR_PIN4,HIGH);
	break;
case CW:
	M_DIO_Void_SetPinValue(DC_MOTOR_PIN3,HIGH);
	M_DIO_Void_SetPinValue(DC_MOTOR_PIN4,LOW);
	break;
}
}
void H_DCMotor_Void_DCMotorStart(void)
{
	//M_Timer_Void_PWMStart(TIMER1_CHANNEL);
	M_DIO_Void_SetPinValue(DC_MOTOR1_EN,HIGH);
	M_DIO_Void_SetPinValue(DC_MOTOR2_EN,HIGH);
}

//sets direction pins of both motors low to stop them
void H_DCMotor_Void_DCMotorStopBoth(void)
{

	M_DIO_Void_SetPinValue(DC_MOTOR_PIN3,LOW);
	M_DIO_Void_SetPinValue(DC_MOTOR_PIN4,LOW);
	M_DIO_Void_SetPinValue(DC_MOTOR_PIN1,LOW);
	M_DIO_Void_SetPinValue(DC_MOTOR_PIN2,LOW);
}

//both motors anticlockwise to move car forward
void H_DCMotor_Void_DCMotorForward(void)
{
	H_DCMotor_Void_DCMotorSetDirection1(ACW);
	H_DCMotor_Void_DCMotorSetDirection2(ACW);

}

//both motors clockwise to move car backward
void H_DCMotor_Void_DCMotorBackward(void)
{
	H_DCMotor_Void_DCMotorSetDirection1(CW);
	H_DCMotor_Void_DCMotorSetDirection2(CW);

}
