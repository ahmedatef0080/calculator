/*
 * Calc.c
 *
 * Created: 8/25/2020 6:28:00 PM
 *  Author: Ahmed Atef
 */ 
#include "KeyPad.h"
#include "LCD_Driver.h"
#define  F_CPU   16000000
#include <util/delay.h>


/* uint8 num1 =0;
 uint8 num2 =0;
 uint8 result=0;

 uint8 op = 0;
 uint8 clear = 0 ;*/

uint8 calc(void)
{
/* uint32 LCD_Size[32];
 uint8 counter=0;
*/
uint32 num1=0;
uint32 num2=0;
uint8 op=0;
uint8 equal=0;
uint32  result =0;
 //uint32 max=32;
  
  while(1)
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

















/*uint8 Calc_Writenum(void)
{
	LCD_goto(1,1);
	
		while(1)
		{
			num1 =KeyPad_GetValue();
			LCD_data(num1);
			op =KeyPad_GetValue();
			LCD_data(op);
			switch(op)
			{
				case '+':
				num2 = KeyPad_GetValue();
				LCD_data(num2);
				result= num1+num2;
				break;
				case '-':
				num2 = KeyPad_GetValue();
				LCD_data(num2);
				result = num1-num2;
				break;
				case '*':
				num2 = KeyPad_GetValue();
				LCD_data(num2);
				result= num1*num2 ;
				break;
				case '/':
				num2 = KeyPad_GetValue();
				LCD_data(num2);
				result= num1+num2;
				break;
				default:
				break;
			}
			
			
			  
			  
			LCD_data(result);	
		}
		

	
}*/