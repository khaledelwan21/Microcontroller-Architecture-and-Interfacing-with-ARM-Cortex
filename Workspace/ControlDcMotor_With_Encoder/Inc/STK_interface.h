/***************************************************
 * Author: khaled elwan
 * Date: 24/8/2026
 * Version: 1.0
 * Description: STK_interface.h
 ***************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H



void STK_voidInit(void);

void STK_Stop(void);

void STK_Reset(void);

u64 STK_GetAHBFrequency(void);

u32 STK_GetRemainingTime_us(void);

u32 STK_GetRemainingTime_ms(void);

u32 STK_delay_ms(u32 Copy_u32DelayTime_ms);

u32  STK_Millis(void);

Std_ReturnType STK_SetIntervalSingle(void (*Copy_CallBackFunc)(void), u32 Copy_u32DelayTime_ms);

Std_ReturnType STK_SetIntervalPeriodic(void (*Copy_CallBackFunc)(void), u32 Copy_u32DelayTime_ms);



#endif