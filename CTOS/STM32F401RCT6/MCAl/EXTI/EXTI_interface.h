/***************************************************
 * Author: khaled elwan
 * Date: 22/8/2026
 * Version: 1.0
 * Description: EXTI_interface.h
 ***************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

Std_ReturnType EXTI_EnableLine(u8 Copy_Line);
Std_ReturnType EXTI_DisableLine(u8 Copy_Line);
Std_ReturnType EXTI_SetTrigger(u8 Copy_Line, u8 Copy_Trigger);
Std_ReturnType EXTI_SelctPort(u8 Copy_Line, u8 Copy_Port);
Std_ReturnType EXTI_SoftwareTrigger(u8 Copy_Line);
Std_ReturnType EXTI_ClearPendingFlag(u8 Copy_Line);



#define RISING_EDGE 0
#define FALLING_EDGE 1
#define ON_CHANGE 2 

















#endif /* EXTI_INTERFACE_H_ */