/***************************************************
 * Author: khaled elwan
 * Date: 17/8/2026
 * Version: 1.0
 * Description: NVIC_interface.h
 ***************************************************/ 
 
 #ifndef NVIC_INTERFACE_H
 #define NVIC_INTERFACE_H
 
 #include  "STD_TYPES.h"
 #include  "BIT_MATH.h"
  
  


 Std_ReturnType NVIC_EnableIRQ( IRQn_Type Copy_IRQn) ;
 
 Std_ReturnType NVIC_DisableIRQ( IRQn_Type Copy_IRQn) ;
 
 Std_ReturnType NVIC_SetPendingIRQ(IRQn_Type Copy_IRQn) ;
 
 Std_ReturnType NVIC_ClearPendingIRQ(IRQn_Type Copy_IRQn) ;
 
 Std_ReturnType NVIC_GetPendingIRQ(IRQn_Type Copy_IRQn,u8 *Copy_ReturnPendingFlag) ;
 
 Std_ReturnType NVIC_SetPriority(IRQn_Type Copy_IRQn, u32 Copy_priority) ;
 
 Std_ReturnType NVIC_GetPriority(IRQn_Type Copy_IRQn) ;
 
 ##endif   /****< NVIC_interface_h ******************/
 
 
 