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

/**************************< TIM2 Registers >******************************************/
typedef struct TIM2_5_Type
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

}TIM2_5_Type;
#define TIM2 ((TIM2_5_Type*)TIM2_BASE_ADDRESS)
#define TIM3 ((TIM2_5_Type*)TIM3_BASE_ADDRESS)
#define TIM4 ((TIM2_5_Type*)TIM4_BASE_ADDRESS)
#define TIM5 ((TIM2_5_Type*)TIM5_BASE_ADDRESS)
/***************************< TIM2_5 Registers >******************************************/
/* CR1 */
#define TIM_CR1_CEN     0
#define TIM_CR1_UDIS    1
#define TIM_CR1_URS     2
#define TIM_CR1_OPM     3
#define TIM_CR1_DIR     4
#define TIM_CR1_ARPE    7

/* DIER / SR / EGR */
#define TIM_DIER_UIE    0
#define TIM_SR_UIF      0
#define TIM_EGR_UG      0


#define EDGE_ALIGNED 0x00
#define CENTER_ALIGNED_MODE_1 0x01
#define CENTER_ALIGNED_MODE_2 0x02
#define CENTER_ALIGNED_MODE_3 0x03

#define ENABLE_BUFFER   1
#define DISABLE_BUFFER  0

#define TIM_CR1_CMS2    4
#define TIM_CR1_CMS0    5
#define TIM_CR1_CMS1    6

#define PWM_MODE_1  0x06   //In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive. In downcounting, channel 1 is inactive as long as TIMx_CNT>TIMx_CCR1 else active.
#define PWM_MODE_2  0x07   //In upcounting, channel 1 is inactive as long as TIMx_CNT<TIMx_CCR1 else active. In downcounting, channel 1 is active as long as TIMx_CNT>TIMx_CCR1 else inactive.

#endif