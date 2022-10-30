#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "STD.h"
#include "Ultrasonic.h"
#include "DIO_Interface.h"
#include "Timer_Interface.h"
#define  Trigger_pin	PA0	//define trigger pin of sensor

int OverflowCount = 0;

ISR(TIMER1_OVF_vect) {
	OverflowCount++;  //Increment Timer Overflow count
}

u32 count;
u8 distance;


u8 Ultrasonic_getDist(void) //function to return distance
{

	M_DIO_Void_SetPinDirection(PA0_PIN,OUTPUT); //Configure Trigger pin as output

	

	sei();// Activate global interrupts


	TIMSK = (1 << TOIE1); //Enable Timer1 overflow interrupt
	TCCR1A = 0;

	PORTA |= (1 << Trigger_pin); //start pulse on trigger pin
	_delay_us(10);//wait 10 us
	PORTA &= (~(1 << Trigger_pin));//stop pulse

	TCNT1 = 0; //Clear timer counter
	TCCR1B = 0x41;
	TIFR = 1 << ICF1; //Clear input capture flage
	TIFR = 1 << TOV1; //Clear Timer Overflow flag



	while ((TIFR & (1 << ICF1)) == 0)//while no rising edge do nothing
		;
	TCNT1 = 0; //Clear Timer counter
	TCCR1B = 0x01;
	TIFR = 1 << ICF1; //Clear input capture flag)
	TIFR = 1 << TOV1; // Clear Timer Overflow flag
	OverflowCount = 0;//Clear Timer overflow count

	while ((TIFR & (1 << ICF1)) == 0)//while no falling edge do nothing
		;
	count = ICR1 + (65535 * OverflowCount); //get count

	distance = (double) count / 57;

	return distance;

}

