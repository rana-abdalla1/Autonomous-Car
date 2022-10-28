#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "STD.h"
#include "LCD_Interface.h"/* Include LCD header file */
#include "Ultrasonic.h"
#include "DIO_Interface.h"
#define  Trigger_pin	PA0	/* Trigger pin */

int TimerOverflow = 0;

ISR(TIMER1_OVF_vect) {
	TimerOverflow++; /* Increment Timer Overflow count */
}

long count;
u8 distance;
/* Set all bit to zero Normal operation */

u8 Ultrasonic_getDist(void) {

	M_DIO_Void_SetPinDirection(PA0_PIN,OUTPUT);
	//DDRA = 0x01; /* Make trigger pin as output */
	PORTD = 0xFF; /* Turn on Pull-up */

	sei();// A

	TIMSK = (1 << TOIE1); //Enable Timer1 overflow interrupt
	TCCR1A = 0;
	/* Give 10us trigger pulse on trig. pin to HC-SR04 */
	PORTA |= (1 << Trigger_pin);
	_delay_us(10);
	PORTA &= (~(1 << Trigger_pin));

	TCNT1 = 0; /* Clear Timer counter */
	TCCR1B = 0x41; /* Capture on rising edge, No prescaler*/
	TIFR = 1 << ICF1; /* Clear ICP flag (Input Capture flag) */
	TIFR = 1 << TOV1; /* Clear Timer Overflow flag */

	/*Calculate width of Echo by Input Capture (ICP) */

	while ((TIFR & (1 << ICF1)) == 0)
		;/* Wait for rising edge */
	TCNT1 = 0; /* Clear Timer counter */
	TCCR1B = 0x01; /* Capture on falling edge, No prescaler */
	TIFR = 1 << ICF1; /* Clear ICP flag (Input Capture flag) */
	TIFR = 1 << TOV1; /* Clear Timer Overflow flag */
	TimerOverflow = 0;/* Clear Timer overflow count */

	while ((TIFR & (1 << ICF1)) == 0)
		;/* Wait for falling edge */
	count = ICR1 + (65535 * TimerOverflow); /* Take count */
	/* 8MHz Timer freq, sound speed =343 m/s */
	distance = (double) count / 57;

	return distance;

}

