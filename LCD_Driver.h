/*
 * LCD_Driver.h
 *
 * Created: 7/20/2020 3:40:47 PM
 *  Author: Ahmed Atef
 */ 


#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#include "LCD_Cfg.h"




void LCD_init(void);
void LCD_command( uint8 cmd);
void LCD_data( uint8 data);
void LCD_goto(uint8 x , uint8 y  ,  sint8*Data);
void LCD_str(uint8 * str);
void clear_LCD( uint8 z);
void LCD_writeint(sint32 num);




#endif /* LCD_DRIVER_H_ */