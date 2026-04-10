/************************************************
 * Author: Khaled Elwan
 * Date: 2026-04-10
 * Description: This file contains the standard data types definitions for the project.
 * version: 1.0
 ************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H  



#define SET_BIT(REG,BIT)     (REG |= (1 << BIT))
#define CLR_BIT(REG,BIT)     (REG &= ~(1 << BIT))
#define TOG_BIT(REG,BIT)     (REG ^= (1 << BIT))
#define GET_BIT(REG,BIT)     ((REG >> BIT) & 1) 

#endif /* BIT_MATH_H */