/*
 * RCcar.c
 *
 * Created: 10/13/2024 9:06:03 PM
 * Author : Rober Maher
 */ 

#include <avr/io.h>
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/UART/UART_interface.h"

#include "../HAL/DCMOTOR/DCMOTOR_interface.h"

#define F_CPU 16000000UL
#include <util/delay.h>



int main(void)
{
	UART_voidInit();
	
	
	while (1)
	{
		if (UART_u8RX()== 'F' || UART_u8RX()== 'f')
		{
			DCMOTOR_voidCW();
		}
		
		else if (UART_u8RX()== 'B' || UART_u8RX()== 'b')
		{
			DCMOTOR_voidACW();
		}
		
		else if (UART_u8RX()== 'R' || UART_u8RX()== 'r')
		{
			DCMOTOR_voidCWRight();
		}
		
		else if (UART_u8RX()== 'L' || UART_u8RX()== 'l')
		{
			DCMOTOR_voidCWLeft();
		}
		
		else if (UART_u8RX()== 'S' || UART_u8RX()== 's')
		{
			DCMOTOR_voidStop();
		}
		
	}
}
