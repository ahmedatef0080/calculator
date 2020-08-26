/*
 * LCD_DRIVER02.c
 *
 * Created: 08/08/2020 03:29:51 م
 * Author : Ali
 */ 

#include "LCD_Driver.h"
#include "KeyPad.h"
#define F_CPU 16000000
#include <util/delay.h>
#include "Calc.h"
int main(void)
{
	
   LCD_init();
   KeyPad_init();
   calc();
   
     uint32 num1=0;
     uint32 num2=0;
     uint8 op=0;
     uint8 equal=0;
     uint32  result =0;
   
    while (1) 
    {
		
		do
		{
			num1=KeyPad_GetValue();
		} while (num1==0xff);
		LCD_data(num1);
		_delay_ms(100);
		do
		{
			op=KeyPad_GetValue();
		} while (op!='+',op!='-',op!='*',op!='/');
		LCD_data(op);
		_delay_ms(100);
		do
		{
			num2=KeyPad_GetValue();
			
		} while (num2==0xff);
		LCD_data(num2);
		_delay_ms(100);
		do
		{
			equal=KeyPad_GetValue();

			
		} while (equal==0xff);

		if(equal== '=')
		{
			switch(op)
			{
				case '+':
				result= num1+num2;
				LCD_data(result);
				break;
				
			}
		}
	}
	
}

