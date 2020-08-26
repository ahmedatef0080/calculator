
/*
 * BIT_MATH.h
 *
 * Created: 8/18/2020 6:59:51 PM
 *  Author: Ahmed Atef
 */ 
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define set_bit(REG,BIT) (REG |= (1<<BIT))
#define clear_bit(REG,BIT) (REG &= ~ (1<<BIT))
#define toggle_bit(REG,BIT) (REG ^=(1<<BIT))
#define GET_BIT(REG,BIT)  ((REG >> BIT) & (0X01))


#endif