/*
 * DIO.h
 *
 * Created: 8/18/2020 7:47:13 PM
 *  Author: Ahmed Atef
 */ 
#ifndef _DIO_H_
#define _DIO_H_


#include "ATmega_Registers.h"
#include "BIT_MATH.h"



#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7


#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW  0
 
 
#define  DIO_PIN_OUT 1
#define  DIO_PIN_IN  0


#define DIO_PORT_OUT 0xFF
#define DIO_PORT_IN 0X00


void DIO_SetPortDirection(uint8 Port , uint8 Dir);
void DIO_SetPinDirection(uint8 Port, uint8 Pin , uint8 Dir);

void DIO_SetPortValue(uint8 Port , uint8 Val);
void DIO_SetPinValue(uint8 Port ,uint8 Pin ,  uint8 Val);

void DIO_ReadPort(uint8 Port , uint8* Val);
void DIO_ReadPin(uint8 Port , uint8 Pin , uint8* Val);
void set_pull_up_resistor(uint8 port , uint8 pin);
void DIO_TogglePin(uint8 Port , uint8 Pin);




#endif