/*
 * LCD_Driver.c
 *
 * Created: 7/20/2020 3:39:57 PM
 *  Author: Ahmed Atef
 */ 
#include "LCD_Driver.h"
#define  F_CPU 16000000
#include <util/delay.h>
void LCD_init(void)
{
	
	DIO_SetPinDirection(LCD_4BIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_OUT);
	DIO_SetPinDirection(LCD_4BIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_OUT);
	DIO_SetPinDirection(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_OUT);
	
	
	
	DIO_SetPinDirection(LCD_4BIT_DATA_PORT,LCD_D4,DIO_PIN_OUT);
	DIO_SetPinDirection(LCD_4BIT_DATA_PORT,LCD_D5,DIO_PIN_OUT);
	DIO_SetPinDirection(LCD_4BIT_DATA_PORT,LCD_D6,DIO_PIN_OUT);
	DIO_SetPinDirection(LCD_4BIT_DATA_PORT,LCD_D7,DIO_PIN_OUT);
	
	
	

	
	_delay_ms(100);
	LCD_command(0x33);
	LCD_command(0x32);
	LCD_command(0x28);
	LCD_command(0x0C);
	LCD_command(0x01);
	LCD_command(0x06);
	LCD_command(0x02);

}
void LCD_command( uint8 cmd)
{
	DIO_SetPinValue(LCD_4BIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);

	/*PORTB &= ~(1<<1);
	PORTB &= ~(1<<2);*/
	PORTA= (PORTA & 0x0F) | (cmd & 0xF0);  // send first 4 bit data
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	// PORTB |= (1<<3);   // set a high to low  pulse
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);
	//PORTB &= ~(1<<3); //set low to high pulse
	PORTA= (PORTA & 0x0F)| (cmd<<4);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	//PORTB |= (1<<3);   // set a low  to high  pulse
	_delay_ms(1);
    DIO_SetPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);

	//PORTB &= ~(1<<3); // send a high to low pulse
	_delay_ms(5);
}
void LCD_data( uint8 data)
{
	DIO_SetPinValue(LCD_4BIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_HIGH);	//PORTB |= (1<<1);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_LOW);	//PORTB &= ~(1<<2);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT ,LCD_E_PIN ,  DIO_PIN_LOW);
	PORTA= (PORTA & 0x0F) | (data & 0xF0);  // send first 4 bit data
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);//PORTB |= (1<<3);   // set a low  to high  pulse
	
	_delay_ms(5);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);	//PORTB &= ~(1<<3); //set high to low  pulse
	PORTA= (PORTA & 0x0F)| (data<<4);
	_delay_ms(1);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	//PORTB |= (1<<3);   // send a low  to high  pulse
	_delay_ms(20);
	DIO_SetPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);
	//PORTB &= ~ (1<<3); // send a high to low pulse
}

void  LCD_goto(uint8 x , uint8 y,  sint8 * Data)
{
	if(x ==2 )
	{
		LCD_command(0xC0);
	}
	for(int i=0;i<y;i++)
	{
		LCD_command(0x14);
	}
	LCD_str(Data);
}
void clear_LCD( uint8 z)
{
	LCD_command(1);
}
void LCD_str(uint8 * str)
{
	while(*str){
		LCD_data(*str++);
	}
	
}
void LCD_writeint(sint32 num)
{
	sint32 y=1;
	if(num<0)
	{
		
	
	LCD_data('-');
	num*=-1;
	}
	while(num>0)
	{
		y=((y*10)+(num%10));
	}
	while(y>1)
	{
		LCD_data((y%10)+48);
		y /=10;
		
	}
	
}