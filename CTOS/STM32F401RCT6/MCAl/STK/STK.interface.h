/***************************************************
 * Author: khaled elwan
 * Date: 24/8/2026
 * Version: 1.0
 * Description: STK_interface.h
 ***************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H



void STK_voidInit(u32 Copy_u32Ticks);


void STK_Stop(void);


void STK_Reset(void);

u32 STK_GetAHBFrequency(void);

u64 STK_GetRemainingTime_us(void);

u32 STK_GetRemainingTime_ms(void);

#endif