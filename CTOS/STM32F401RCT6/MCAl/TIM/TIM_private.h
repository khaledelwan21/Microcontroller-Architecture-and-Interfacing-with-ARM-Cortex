/************************************************** 
* Author: Khaled Ahmed Elwan
* Date: 19/9/2026
* Version: 1.0
* Description: TIM_private.h
***************************************************/
#ifndef TIM_PRIVATE_H
#define TIM_PRIVATE_H

#define TIM1_BASE_ADDRESS  0x40010000
#define TIM2_BASE_ADDRESS  0x40000000
#define TIM3_BASE_ADDRESS  0x40000400
#define TIM4_BASE_ADDRESS  0x40000800
#define TIM5_BASE_ADDRESS  0x40000C00
#define TIM9_BASE_ADDRESS  0x40014000
#define TIM10_BASE_ADDRESS 0x40014400
#define TIM11_BASE_ADDRESS 0x40014800

/**************************< TIM1 Registers >******************************************/
typedef struct TIM1_Type
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SMCR;
    volatile u32 DIER;
    volatile u32 SR;
    volatile u32 EGR;
    volatile u32 CCMR1;
    volatile u32 CCMR2;
    volatile u32 CCER;
    volatile u32 CNT;
    volatile u32 PSC;
    volatile u32 ARR;
    volatile u32 RCR;
    volatile u32 CCR1;
    volatile u32 CCR2;
    volatile u32 CCR3;
    volatile u32 CCR4;
    volatile u32 BDTR;
    volatile u32 DCR;
    volatile u32 DMAR;

}TIM1_Type;
#define TIM1 ((TIM1_Type*)TIM1_BASE_ADDRESS)

/**************************< TIM2 Registers >******************************************/
typedef struct TIM2_Type
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SMCR;
    volatile u32 DIER;
    volatile u32 SR;
    volatile u32 EGR;
    volatile u32 CCMR1;
    volatile u32 CCMR2;
    volatile u32 CCER;
    volatile u32 CNT;
    volatile u32 PSC;
    volatile u32 ARR;
    volatile u32 CCR1;
    volatile u32 CCR2;
    volatile u32 CCR3;
    volatile u32 CCR4;
    volatile u32 DCR;
    volatile u32 DMAR;

}TIM2_Type;
#define TIM2 ((TIM2_Type*)TIM2_BASE_ADDRESS)

/**************************< TIM3 Registers >******************************************/
typedef struct TIM3_Type
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SMCR;
    volatile u32 DIER;
    volatile u32 SR;
    volatile u32 EGR;
    volatile u32 CCMR1;     
    volatile u32 CCMR2;
    volatile u32 CCER;
    volatile u32 CNT;
    volatile u32 PSC;
    volatile u32 ARR;
    volatile u32 CCR1;
    volatile u32 CCR2;
    volatile u32 CCR3;
    volatile u32 CCR4;
    volatile u32 DCR;
    volatile u32 DMAR;  

}TIM3_Type;
#define TIM3 ((TIM3_Type*)TIM3_BASE_ADDRESS)

/***************************< TIM4 Registers >*******************************************/

typedef struct TIM4_Type
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SMCR;
    volatile u32 DIER;
    volatile u32 SR;
    volatile u32 EGR;
    volatile u32 CCMR1;     
    volatile u32 CCMR2;
    volatile u32 CCER;
    volatile u32 CNT;
    volatile u32 PSC;
    volatile u32 ARR;
    volatile u32 CCR1;
    volatile u32 CCR2;
    volatile u32 CCR3;
    volatile u32 CCR4;
    volatile u32 DCR;
    volatile u32 DMAR;  

}TIM4_Type;
#define TIM4 ((TIM4_Type*)TIM4_BASE_ADDRESS)

/***************************< TIM5 Registers >*******************************************/
typedef struct TIM5_Type
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SMCR;
    volatile u32 DIER;
    volatile u32 SR;
    volatile u32 EGR;
    volatile u32 CCMR1;     
    volatile u32 CCMR2;
    volatile u32 CCER;     
    volatile u32 CNT;   
    volatile u32 PSC;
    volatile u32 ARR;
    volatile u32 CCR1;
    volatile u32 CCR2;
    volatile u32 CCR3;
    volatile u32 CCR4;
    volatile u32 DCR;
    volatile u32 DMAR;  

}TIM5_Type; 
#define TIM5 ((TIM5_Type*)TIM5_BASE_ADDRESS)

/***************************< TIM9 Registers >*******************************************/
typedef struct TIM9_Type
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SMCR;
    volatile u32 DIER;
    volatile u32 SR;
    volatile u32 EGR;
    volatile u32 CCMR1;     
    volatile u32 CCMR2;
    volatile u32 CCER;     
    volatile u32 CNT;   
    volatile u32 PSC;
    volatile u32 ARR;
    volatile u32 CCR1;
    volatile u32 CCR2;
    volatile u32 CCR3;
    volatile u32 CCR4;
    volatile u32 DCR;
    volatile u32 DMAR;  

}TIM9_Type; 
#define TIM9 ((TIM9_Type*)TIM9_BASE_ADDRESS)

/***************************< TIM10 Registers >*****************************************/
typedef struct TIM10_Type
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SMCR;
    volatile u32 DIER;
    volatile u32 SR;
    volatile u32 EGR;
    volatile u32 CCMR1;     
    volatile u32 CCMR2;
    volatile u32 CCER;     
    volatile u32 CNT;   
    volatile u32 PSC;
    volatile u32 ARR;
    volatile u32 CCR1;
    volatile u32 CCR2;
    volatile u32 CCR3;
    volatile u32 CCR4;
    volatile u32 DCR;
    volatile u32 DMAR;  

}TIM10_Type; 
#define TIM10 ((TIM10_Type*)TIM10_BASE_ADDRESS)

/***************************< TIM11 Registers >*****************************************/
typedef struct TIM11_Type
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SMCR;
    volatile u32 DIER;
    volatile u32 SR;
    volatile u32 EGR;
    volatile u32 CCMR1;     
    volatile u32 CCMR2;
    volatile u32 CCER;     
    volatile u32 CNT;   
    volatile u32 PSC;
    volatile u32 ARR;
    volatile u32 CCR1;
    volatile u32 CCR2;
    volatile u32 CCR3;
    volatile u32 CCR4;
    volatile u32 DCR;
    volatile u32 DMAR;  

}TIM11_Type; 
#define TIM11 ((TIM11_Type*)TIM11_BASE_ADDRESS) 



#endif