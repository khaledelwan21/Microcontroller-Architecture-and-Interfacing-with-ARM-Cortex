/**************************************************
* Author: Khaled Ahmed Elwan
* Date: 19/9/2026
* Version: 2.0
* Description: TIM_private.h  (STM32F401RCT6 - TIM2..TIM5, TIM9..TIM11)
***************************************************/
#ifndef TIM_PRIVATE_H
#define TIM_PRIVATE_H

#include "STD_TYPES.h"

/**************************< Base addresses >******************************/
/* (wrapped with #ifndef so a host-side unit test can override them) */
#ifndef TIM2_BASE_ADDRESS
#define TIM2_BASE_ADDRESS   0x40000000UL    /* APB1 */
#define TIM3_BASE_ADDRESS   0x40000400UL    /* APB1 */
#define TIM4_BASE_ADDRESS   0x40000800UL    /* APB1 */
#define TIM5_BASE_ADDRESS   0x40000C00UL    /* APB1 */
#define TIM9_BASE_ADDRESS   0x40014000UL    /* APB2 */
#define TIM10_BASE_ADDRESS  0x40014400UL    /* APB2 */
#define TIM11_BASE_ADDRESS  0x40014800UL    /* APB2 */
#endif

/**************************< Register map >********************************
 * One struct for all 7 timers. TIM2..TIM5 are the full version, TIM9..TIM11
 * are subsets that keep the SAME offsets, so a single struct works for all.
 * Registers marked "not present" must not be touched on that timer
 * (the capability table in TIM_program.c protects against this).
 **************************************************************************/
typedef struct TIM_RegDef_t
{
    volatile u32 CR1;        /* 0x00                                   */
    volatile u32 CR2;        /* 0x04  not present in TIM9/10/11        */
    volatile u32 SMCR;       /* 0x08  not present in TIM10/11          */
    volatile u32 DIER;       /* 0x0C                                   */
    volatile u32 SR;         /* 0x10                                   */
    volatile u32 EGR;        /* 0x14                                   */
    volatile u32 CCMR1;      /* 0x18                                   */
    volatile u32 CCMR2;      /* 0x1C  not present in TIM9/10/11        */
    volatile u32 CCER;       /* 0x20                                   */
    volatile u32 CNT;        /* 0x24                                   */
    volatile u32 PSC;        /* 0x28                                   */
    volatile u32 ARR;        /* 0x2C                                   */
    volatile u32 RESERVED0;  /* 0x30                                   */
    volatile u32 CCR1;       /* 0x34                                   */
    volatile u32 CCR2;       /* 0x38  not present in TIM10/11          */
    volatile u32 CCR3;       /* 0x3C  not present in TIM9/10/11        */
    volatile u32 CCR4;       /* 0x40  not present in TIM9/10/11        */
    volatile u32 RESERVED1;  /* 0x44                                   */
    volatile u32 DCR;        /* 0x48  not present in TIM9/10/11        */
    volatile u32 DMAR;       /* 0x4C  not present in TIM9/10/11        */
    volatile u32 OR;         /* 0x50  TIM2, TIM5, TIM11 only           */
} TIM_RegDef_t;

#define TIM2    ((TIM_RegDef_t*)TIM2_BASE_ADDRESS)
#define TIM3    ((TIM_RegDef_t*)TIM3_BASE_ADDRESS)
#define TIM4    ((TIM_RegDef_t*)TIM4_BASE_ADDRESS)
#define TIM5    ((TIM_RegDef_t*)TIM5_BASE_ADDRESS)
#define TIM9    ((TIM_RegDef_t*)TIM9_BASE_ADDRESS)
#define TIM10   ((TIM_RegDef_t*)TIM10_BASE_ADDRESS)
#define TIM11   ((TIM_RegDef_t*)TIM11_BASE_ADDRESS)

/**************************< Bit positions >*******************************/
/* CR1 */
#define TIM_CR1_CEN     0
#define TIM_CR1_UDIS    1
#define TIM_CR1_URS     2
#define TIM_CR1_OPM     3
#define TIM_CR1_DIR     4       /* TIM2..TIM5 only */
#define TIM_CR1_CMS0    5       /* TIM2..TIM5 only */
#define TIM_CR1_CMS1    6       /* TIM2..TIM5 only */
#define TIM_CR1_ARPE    7

/* DIER / SR / EGR */
#define TIM_DIER_UIE    0
#define TIM_SR_UIF      0
#define TIM_EGR_UG      0

/**************************< Config values >*******************************/
#define EDGE_ALIGNED            0x00
#define CENTER_ALIGNED_MODE_1   0x01
#define CENTER_ALIGNED_MODE_2   0x02
#define CENTER_ALIGNED_MODE_3   0x03

#define ENABLE_BUFFER           1
#define DISABLE_BUFFER          0

#endif