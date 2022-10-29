#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "STD.h"
#include "LCD_Interface.h"
#include "Ultrasonic.h"
#include "Servo_Interface.h"
#include "Timer_Interface.h"
#include "DCMotor_Interface.h"

int main()
{

	u8 dist;
	u8 distRight;
	u8 distLeft;

	H_Servo_Void_ServoInit();
	H_DCMotor_Void_DCMotorInit();
	while (1)
	{
		H_Servo_Void_ServoForward();
		H_LCD_Void_LCDInit();

		H_DCMotor_Void_DCMotorForward();
		H_DCMotor_Void_DCMotorStart();
		dist = Ultrasonic_getDist();

		//while obstacle close
		while (dist < 20)
		{
			H_DCMotor_Void_DCMotorStopBoth(); //Stop Car

			H_Servo_Void_ServoRight(); // Set angle right
			H_Servo_Void_ServoSetStart();
			H_LCD_Void_LCDWriteString((u8*) "Servo right");
			_delay_ms(1000);
			H_LCD_Void_LCDClear();
			_delay_ms(10000);
			distRight = Ultrasonic_getDist();
			H_LCD_Void_LCDWriteNumber(distRight);
			_delay_ms(1000);
			H_LCD_Void_LCDClear();

			H_Servo_Void_ServoLeft(); // Set angle left
			H_Servo_Void_ServoSetStart();
			H_LCD_Void_LCDWriteString((u8*) "Servo left");
			_delay_ms(1000);
			H_LCD_Void_LCDClear();
			_delay_ms(10000);
			distLeft = Ultrasonic_getDist();
			H_LCD_Void_LCDWriteNumber(distLeft);
			_delay_ms(1000);
			H_LCD_Void_LCDClear();

			H_Servo_Void_ServoForward(); // Face forward
			H_Servo_Void_ServoSetStart();
			_delay_ms(10000);

			//decide which direction to turn
			if (distRight > distLeft)
			{
				dist = distRight;
				if (dist > 20)
				{
					H_DCMotor_Void_DCMotorTurnRight(); //turn left wheel
					_delay_ms(1000);
					H_DCMotor_Void_DCMotorForward(); //turn both wheels
					H_LCD_Void_LCDWriteString((u8*) "Car  right");
					_delay_ms(10000);
					H_LCD_Void_LCDClear();
					break;
				}
			}
			else 
			{
				dist = distLeft;
				if (dist > 20)
				{

					H_DCMotor_Void_DCMotorTurnLeft(); //turn right wheel
					_delay_ms(1000);
					H_DCMotor_Void_DCMotorForward(); //turn both wheels
					H_LCD_Void_LCDWriteString((u8*) "Cart left");
					_delay_ms(10000);
					H_LCD_Void_LCDClear();
					break;
				}
			}

		}
	}
}

