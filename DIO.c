/*
 * DIO.c
 *
 * Created: 8/18/2020 7:06:57 PM
 *  Author: Ahmed Atef
 */ 
#include "DIO.h"




void DIO_SetPortDirection(uint8 Port , uint8 Dir)
{
	switch(Port)
	{
		
	
	case DIO_PORTA :
	DDRA = Dir ;
	break;
	case DIO_PORTB :
	DDRB = Dir ;
	break;
	case DIO_PORTC:
	DDRC = Dir;
	break;
	case DIO_PORTD:
	DDRD = Dir;
	break;
	default:
	break;
	}
}
void DIO_SetPinDirection(uint8 port, uint8 pin , uint8 Dir) //Direction == input , output ;
{
	switch(Dir)
	{
		
	
	case DIO_PIN_OUT:
	switch(port)
	{
		
	
	case DIO_PORTA:
	set_bit(DDRA,pin);
	break;
	case DIO_PORTB:
	set_bit(DDRB,pin);
	break;
	case DIO_PORTC:
	set_bit(DDRC,pin);
	break;
	case DIO_PORTD:
	set_bit(DDRD,pin);
	break;
	default:
	break;
	}
	break;
	
	case DIO_PIN_IN:
	switch(port)
	{
		
		
		case DIO_PORTA:
		clear_bit(DDRA,pin);
		break;
		case DIO_PORTB:
		clear_bit(DDRB,pin);
		break;
		case DIO_PORTC:
		clear_bit(DDRC,pin);
		break;
		case DIO_PORTD:
		clear_bit(DDRD,pin);
		break;
		default:
		break;
	}
	default:
	break;
	}
	
	
}
void DIO_SetPortValue(uint8 Port , uint8 Val)
{
	switch(Port)
	{
	 case DIO_PORTA:
	 PORTA = Val;
	 break;
	  case DIO_PORTB:
	  PORTA = Val;
	  break;
	   case DIO_PORTC:
	   PORTA = Val;
	   break;
	    case DIO_PORTD:
	    PORTA = Val;
	    break;
		default:
		break;
	}

}
void DIO_SetPinValue(uint8 Port ,uint8 Pin ,  uint8 Val) // val== high or low "1,0";
{
	switch(Val)
	{
		case DIO_PIN_HIGH:
		switch(Port)
		{
			case DIO_PORTA:
			set_bit(PORTA,Pin);
			break;
			case DIO_PORTB:
			set_bit(PORTB,Pin);
			break;
			case DIO_PORTC:
			set_bit(PORTC,Pin);
			break;
			case DIO_PORTD:
			set_bit(PORTD,Pin);
			break;
			default:
			break;
		}
		break;
		case DIO_PIN_LOW:
		switch(Port)
		{
			case DIO_PORTA:
			clear_bit(PORTA,Pin);
			break;
			case DIO_PORTB:
			clear_bit(PORTB,Pin);
			break;
			case DIO_PORTC:
			clear_bit(PORTC,Pin);
			break;
			case DIO_PORTD:
			clear_bit(PORTD,Pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
		
	}
}
void DIO_ReadPort(uint8 Port , uint8* Val)
{
	switch (Port)
	{
		case DIO_PORTA :
		*Val = PINA;
		break;
		
		case DIO_PORTB :
		*Val = PINB;
		break;
		
		case DIO_PORTC :
		*Val = PINC;
		break;
		
		case DIO_PORTD :
		*Val = PIND;
		break;
		
		default:
		break;
	}
	
}
void DIO_ReadPin(uint8 Port , uint8 Pin , uint8* Val)
{
	switch (Port)
	{
		case DIO_PORTA :
		*Val = GET_BIT(PINA,Pin);
		break;
		
		case DIO_PORTB :
		*Val = GET_BIT(PINB,Pin);
		break;
		
		case DIO_PORTC :
		*Val = GET_BIT(PINC,Pin);
		break;
		
		case DIO_PORTD :
		*Val = GET_BIT(PIND,Pin);
		break;
		
		default:
		break;
	}
}
void DIO_TogglePin(uint8 Port , uint8 Pin)
{
	switch(Port)
	{
		case DIO_PORTA :
		
		toggle_bit(PORTA, Pin);
		
		break;
		
		case DIO_PORTB :
		
		toggle_bit(PORTB, Pin);
		
		break;
		
		case DIO_PORTC :
		
		toggle_bit(PORTC, Pin);
		
		break;
		
		case DIO_PORTD :
		
		toggle_bit(PORTD, Pin);
		
		break;
		
		default:
		break;
	}
}
void set_pull_up_resistor(uint8 port , uint8 pin)
{
	switch(port)
	{
		case DIO_PORTA :
		set_bit(PORTA,pin);
		break;
		case DIO_PORTB:
		set_bit(PORTB,pin);
		break;
		case DIO_PORTC:
		set_bit(PORTC,pin);
		break;
		case DIO_PORTD:
		set_bit(PORTD,pin);
		break;
		default:
		break;
	}
	
}