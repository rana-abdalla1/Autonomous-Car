/*
 * LCD_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"
#include "DIO_Interface.h"
#define LCD_D0_PIN       PA0_PIN
#define LCD_D1_PIN       PA1_PIN
#define LCD_D2_PIN       PA2_PIN
#define LCD_D3_PIN       PA3_PIN
#define LCD_D4_PIN       PA4_PIN
#define LCD_D5_PIN       PA5_PIN
#define LCD_D6_PIN       PA6_PIN
#define LCD_D7_PIN       PA7_PIN
#define LCD_EN_PIN       PB3_PIN
#define LCD_RW_PIN       PB2_PIN
#define LCD_RS_PIN       PB1_PIN

void H_LCD_Void_LCDInit(void)
{


	M_DIO_Void_SetPinDirection(LCD_D4_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D6_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D7_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RS_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_EN_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RW_PIN,OUTPUT);
	M_DIO_Void_SetPinValue(LCD_RW_PIN,LOW);

	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_1);
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_2);
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_3);

	H_LCD_Void_LCDWriteCommand(LCD_DISPLAY_ON_CURSOR_OFF);
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR);
	H_LCD_Void_LCDWriteCommand(LCD_RETURN_HOME);

}
void H_LCD_Void_LCDWriteCharacter(u8 Copy_U8_Character)
{
	M_DIO_Void_SetPinValue(LCD_RS_PIN,HIGH);
#if   LCD_MODE   ==   _8_BIT_MODE
	H_LCD_Void_SetLCDPins(Copy_U8_Character);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
#elif LCD_MODE   ==   _4_BIT_MODE
	H_LCD_Void_SetLCDPins(Copy_U8_Character >> 4);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
	_delay_ms(1);
	H_LCD_Void_SetLCDPins(Copy_U8_Character);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
#endif
	_delay_ms(1);
}
void H_LCD_Void_LCDWriteCommand(u8 Copy_U8_Command)
{
	M_DIO_Void_SetPinValue(LCD_RS_PIN,LOW);


	H_LCD_Void_SetLCDPins(Copy_U8_Command >> 4);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);
	_delay_ms(1);
	H_LCD_Void_SetLCDPins(Copy_U8_Command);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PIN,LOW);

	_delay_ms(1);
}
void H_LCD_Void_LCDWriteString(u8* Copy_U8_P)
{
	u8 Local_U8_Counter = 0;
	while(Copy_U8_P[Local_U8_Counter] != '\0')
	{
		H_LCD_Void_LCDWriteCharacter(Copy_U8_P[Local_U8_Counter]);
		Local_U8_Counter++;
	}
}
void H_LCD_Void_LCDWriteNumber(s32 Copy_S32_Num)
{
	s8 Local_S8_Counter = -1;
	u8 Local_U8_Arr[16];
	if(Copy_S32_Num < 0)
	{
		Copy_S32_Num = Copy_S32_Num * -1;
		H_LCD_Void_LCDWriteCharacter('-');
	}
	do
	{
		Local_S8_Counter++;
		Local_U8_Arr[Local_S8_Counter]  =  Copy_S32_Num % 10;
		Copy_S32_Num = Copy_S32_Num / 10;
	}while(Copy_S32_Num != 0);
	while(Local_S8_Counter >= 0)
	{
		H_LCD_Void_LCDWriteCharacter(Local_U8_Arr[Local_S8_Counter] + 48);
		Local_S8_Counter--;
	}


}





void H_LCD_Void_LCDGoTo(u8 Copy_U8_Row,u8 Copy_U8_Col)
{
	u8 Local_U8Arr [2] = {0x80 , 0xC0};
	H_LCD_Void_LCDWriteCommand(Local_U8Arr[Copy_U8_Row] + Copy_U8_Col);
}















void H_LCD_Void_LCDClear(void)
{
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR);
}

static void H_LCD_Void_SetLCDPins(u8 Copy_U8_Pins)
{


	M_DIO_Void_SetPinValue(LCD_D4_PIN,Copy_U8_Pins >> 0 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D5_PIN,Copy_U8_Pins >> 1 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D6_PIN,Copy_U8_Pins >> 2 & 0x01);
	M_DIO_Void_SetPinValue(LCD_D7_PIN,Copy_U8_Pins >> 3 & 0x01);

}
