/***************************************************
 * Author: khaled elwan
 * Date: 22/8/2026
 * Version: 1.0
 * Description: EXTI_private.h
 ***************************************************/


 #ifndef EXTI_PRIVATE_H
 #define EXTI_PRIVATE_H



 #define EXTI_BASE_ADDRESS 0x40013C00

 #define EXTI ((EXTI_t *)EXTI_BASE_ADDRESS)
 #define EXTI_IMR *((volatile u32 *)(EXTI_BASE_ADDRESS + 0x00))
 #define EXTI_EMR *((volatile u32 *)(EXTI_BASE_ADDRESS + 0x04))
 #define EXTI_RTSR *((volatile u32 *)(EXTI_BASE_ADDRESS + 0x08))
 #define EXTI_FTSR *((volatile u32 *)(EXTI_BASE_ADDRESS + 0x0C))
 #define EXTI_SWIER *((volatile u32 *)(EXTI_BASE_ADDRESS + 0x10))
 #define EXTI_PR *((volatile u32 *)(EXTI_BASE_ADDRESS + 0x14))


 











 #endif /* EXTI_PRIVATE_H */