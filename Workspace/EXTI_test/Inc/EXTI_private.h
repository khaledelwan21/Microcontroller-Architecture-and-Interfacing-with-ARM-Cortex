/***************************************************
 * Author: khaled elwan
 * Date: 22/8/2026
 * Version: 1.0
 * Description: EXTI_private.h
 ***************************************************/


 #ifndef EXTI_PRIVATE_H
 #define EXTI_PRIVATE_H



 #define EXTI_BASE_ADDRESS 0x40013C00


 #define EXTI_IMR *((volatile u32 *)(EXTI_BASE_ADDRESS + 0x00))
 #define EXTI_EMR *((volatile u32 *)(EXTI_BASE_ADDRESS + 0x04))
 #define EXTI_RTSR *((volatile u32 *)(EXTI_BASE_ADDRESS + 0x08))
 #define EXTI_FTSR *((volatile u32 *)(EXTI_BASE_ADDRESS + 0x0C))
 #define EXTI_SWIER *((volatile u32 *)(EXTI_BASE_ADDRESS + 0x10))
 #define EXTI_PR *((volatile u32 *)(EXTI_BASE_ADDRESS + 0x14))



 #define SYSCFG_BASE_ADDRESS     0x40013800

 #define SYSCFG_EXTICR ((volatile u32 *)(SYSCFG_BASE_ADDRESS + 0x08))


#define EXTI_LINES_Count 16

#define EXTI_LINE0 0
#define EXTI_LINE1 1
#define EXTI_LINE2 2
#define EXTI_LINE3 3
#define EXTI_LINE4 4
#define EXTI_LINE5 5
#define EXTI_LINE6 6
#define EXTI_LINE7 7     
#define EXTI_LINE8 8
#define EXTI_LINE9 9
#define EXTI_LINE10 10
#define EXTI_LINE11 11
#define EXTI_LINE12 12
#define EXTI_LINE13 13
#define EXTI_LINE14 14
#define EXTI_LINE15 15 




 #endif /* EXTI_PRIVATE_H */