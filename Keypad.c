/*
 * Keypad.c
 *
 * Created: 8/23/2020 8:05:06 PM
 *  Author: Ahmed Atef
 */ 
#include "keypad.h"
#define F_CPU 16000000
#include "util/delay.h"


#define init_colum  0
#define final_coulm 3

#define init_row    4
#define final_row   7

// declare the keypad at software 

const uint8 KeyPad_Values[4][4]    =   { {'7' , '8' , '9' , '/'},
										 {'4' , '5' , '6' , '*'},
										 {'1' , '2' , '3' , '-'},
										 {'c' , '0' , '=' , '+'} };
							
	
 void KeyPad_init(void)
 {
	 // set all coulms as output as default of keypad 
	 DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_Colum0,DIO_PIN_OUT);
	 DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_Colum1,DIO_PIN_OUT);
	 DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_Colum2,DIO_PIN_OUT);
	 DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_Colum3,DIO_PIN_OUT);
	 
	 //set all rows as input as defualt of keypad 
	 
	 	 DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_Row0,DIO_PIN_IN);
		 DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_Row1,DIO_PIN_IN);
	 	 DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_Row2,DIO_PIN_IN);
	 	 DIO_SetPinDirection(KEYPAD_PORT,KEYPAD_Row3,DIO_PIN_IN);
		  
		  // set all rows with pull up resistor as default of keypad 
		  
		set_pull_up_resistor(KEYPAD_PORT,KEYPAD_Row0);
		set_pull_up_resistor(KEYPAD_PORT,KEYPAD_Row1);
		set_pull_up_resistor(KEYPAD_PORT,KEYPAD_Row2);
		set_pull_up_resistor(KEYPAD_PORT,KEYPAD_Row3);
		
		
		
		// set high to all coulms to add lows at coulms by looping at the coulms
		
	DIO_SetPinValue(KEYPAD_PORT,KEYPAD_Colum0,DIO_PIN_HIGH);  
	DIO_SetPinValue(KEYPAD_PORT,KEYPAD_Colum1,DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_PORT,KEYPAD_Colum2,DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_PORT,KEYPAD_Colum3,DIO_PIN_HIGH);
	 
 }
 
 
uint8 KeyPad_GetValue(void)
{
	uint8 location_colum =0;
	uint8 location_rows =0;
	uint8 value=0;
	uint8  get_value=0;
	
	// d5lt el cloum w el rows fe loop 3shan y3vdl y3ml set low l el colum w y3ml set high l b2i el coloums  
	
	for(location_colum= init_colum;location_colum <= final_coulm;location_colum++)
	{
		DIO_SetPinValue(KEYPAD_PORT,location_colum,DIO_PIN_LOW); // PORTD&= ~(1<<n)
		
		
		for(location_rows= init_row;location_rows <= final_row;location_rows++)
		{
			DIO_ReadPin(KEYPAD_PORT,location_rows,&get_value); // (PORTD >> n) &(0x01) 
			
			if(!get_value) // if(0) msh hy5osh fe el if , if(1) "! bt2leb el 0 t5lih 1 " hy5osh fe el if 
			{
				value = KeyPad_Values[location_rows - init_row][location_colum - init_colum];
				while(!get_value)
				{
								DIO_ReadPin(KEYPAD_PORT , location_rows , &get_value);
					
				}
				_delay_ms(20);
			}
						
		}
		DIO_SetPinValue(KEYPAD_PORT,location_colum,DIO_PIN_HIGH); // put 1 to colums again to switch between colums 
		
	}
			return value;

}