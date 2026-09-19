/***************************************************
 * Author: khaled elwan
 * Date: 10/4/2026
 * Version: 1.0
 * Description: RCC_interface.h
 ***************************************************/           
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


#include "STD_TYPES.h"
#include "RCC_private.h"
#include "RCC_config.h"


#define RCC_AHB1_BUS		 0
#define RCC_AHB2_BUS		 1
#define RCC_APB1_BUS 		 2
#define RCC_APB2_BUS 		 3



Std_ReturnType RCC_InitSysClock(void);

Std_ReturnType RCC_EnablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);

Std_ReturnType RCC_DisablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);

Std_ReturnType RCC_GetFrequency(u32 *Copy_pu32Frequency);

#endif /* RCC_INTERFACE_H */   
 