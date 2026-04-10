/***************************************************
 * Author: khaled elwan
 * Date: 10/4/2026
 * Version: 1.0
 * Description: RCC_interface.h
 ***************************************************/           
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

Std_ReturnType RCC_voidInitSysClock(void);
Std_ReturnType RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
Std_ReturnType RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId); 

#endif /* RCC_INTERFACE_H */   