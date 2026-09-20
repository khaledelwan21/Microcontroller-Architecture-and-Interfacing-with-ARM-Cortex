/********************************************************************
* Author: Khaled Ahmed Elwan
* Date: 19/9/2026
* Version: 1.1
* Description: TIM_program.c  (STM32F401RCT6 - TIM2..TIM5)
*********************************************************************/

/***************************< LIB ***********************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/***************************< MCAL **********************************/
#include "TIM_interface.h"
#include "TIM_private.h"
#include "TIM_config.h"

/***************************< PRIVATE DATA ***************************/
/* If the register struct in TIM_private.h has a different name, change it here */
static TIM_RegDef_t * const TIM_Reg[4] = { TIM2, TIM3, TIM4, TIM5 };

static const uint32_t TIM_PscCfg[4]  = { TIM2_PSC,  TIM3_PSC,  TIM4_PSC,  TIM5_PSC  };
static const uint32_t TIM_ArrCfg[4]  = { TIM2_ARR,  TIM3_ARR,  TIM4_ARR,  TIM5_ARR  };
static const uint8_t  TIM_DirCfg[4]  = { TIM2_DIR,  TIM3_DIR,  TIM4_DIR,  TIM5_DIR  };
static const uint8_t  TIM_ModeCfg[4] = { TIM2_MODE, TIM3_MODE, TIM4_MODE, TIM5_MODE };
static const uint8_t  TIM_BufCfg[4]  = { TIM2_BUFFER_MODE, TIM3_BUFFER_MODE,
                                         TIM4_BUFFER_MODE, TIM5_BUFFER_MODE };

/***************************< PRIVATE HELPERS ************************/

/* Converts the timer ID to an array index (0..3), independent of the enum values.
 * Returns -1 for an invalid ID. */
static int8_t TIM_s8GetIndex(TIM_Id_t Copy_Id)
{
    switch (Copy_Id)
    {
        case TIM_2: return 0;
        case TIM_3: return 1;
        case TIM_4: return 2;
        case TIM_5: return 3;
        default:    return -1;
    }
}

/* Converts CHANNEL_x to a channel index (0..3), independent of the macro values.
 * Returns -1 for an invalid channel. */
static int8_t TIM_s8GetChannelIndex(uint8_t Copy_Channel)
{
    switch (Copy_Channel)
    {
        case CHANNEL_1: return 0;
        case CHANNEL_2: return 1;
        case CHANNEL_3: return 2;
        case CHANNEL_4: return 3;
        default:        return -1;
    }
}

/* Only TIM2 and TIM5 have a 32-bit counter (TIM3/TIM4 are 16-bit) */
static uint8_t TIM_u8Is32Bit(int8_t Copy_Idx)
{
    return (Copy_Idx == 0 || Copy_Idx == 3);
}

/* Applies the counter alignment (CR1.CMS bits) */
static void TIM_voidApplyAlignment(TIM_RegDef_t *Copy_Tim, uint8_t Copy_Mode)
{
    if (Copy_Mode == EDGE_ALIGNED)
    {
        CLR_BIT(Copy_Tim->CR1, TIM_CR1_CMS0);
        CLR_BIT(Copy_Tim->CR1, TIM_CR1_CMS1);
    }
    else if (Copy_Mode == CENTER_ALIGNED_MODE_1)
    {
        SET_BIT(Copy_Tim->CR1, TIM_CR1_CMS0);
        CLR_BIT(Copy_Tim->CR1, TIM_CR1_CMS1);
    }
    else if (Copy_Mode == CENTER_ALIGNED_MODE_2)
    {
        CLR_BIT(Copy_Tim->CR1, TIM_CR1_CMS0);
        SET_BIT(Copy_Tim->CR1, TIM_CR1_CMS1);
    }
    else if (Copy_Mode == CENTER_ALIGNED_MODE_3)
    {
        SET_BIT(Copy_Tim->CR1, TIM_CR1_CMS0);
        SET_BIT(Copy_Tim->CR1, TIM_CR1_CMS1);
    }
}

/*===============================< TIM_voidInit >==========================
 * Applies the static configuration from TIM_config.h.
 * The timer clock must be enabled from the RCC driver before calling this. */
void TIM_voidInit(TIM_Id_t Copy_Id)
{
    int8_t idx = TIM_s8GetIndex(Copy_Id);
    if (idx < 0) return;

    TIM_RegDef_t *t = TIM_Reg[idx];

    /* 1) Counter alignment (CMS) */
    TIM_voidApplyAlignment(t, TIM_ModeCfg[idx]);

    /* 2) Direction: only applies in edge-aligned mode (DIR is read-only in center-aligned) */
    if (TIM_ModeCfg[idx] == EDGE_ALIGNED)
    {
        if (TIM_DirCfg[idx] == 0) { CLR_BIT(t->CR1, TIM_CR1_DIR); }
        else                      { SET_BIT(t->CR1, TIM_CR1_DIR); }
    }

    /* 3) Auto-reload preload (ARPE) */
    if (TIM_BufCfg[idx] == ENABLE_BUFFER) { SET_BIT(t->CR1, TIM_CR1_ARPE); }
    else                                  { CLR_BIT(t->CR1, TIM_CR1_ARPE); }

    /* 4) Prescaler and auto-reload values */
    t->PSC = TIM_PscCfg[idx];
    t->ARR = TIM_ArrCfg[idx];
}

/*===============================< TIM_voidSetPrescaler >==================*/
void TIM_voidSetPrescaler(TIM_Id_t Copy_Id, uint32_t Copy_Psc)
{
    int8_t idx = TIM_s8GetIndex(Copy_Id);
    if (idx < 0) return;

    TIM_Reg[idx]->PSC = Copy_Psc;
}

/*===============================< TIM_voidSetPeriod >=====================*/
void TIM_voidSetPeriod(TIM_Id_t Copy_Id, uint32_t Copy_Arr)
{
    int8_t idx = TIM_s8GetIndex(Copy_Id);
    if (idx < 0) return;

    TIM_Reg[idx]->ARR = Copy_Arr;   /* TIM3/TIM4 are 16-bit only */
}

/*===============================< TIM_voidStart >=========================*/
void TIM_voidStart(TIM_Id_t Copy_Id)
{
    int8_t idx = TIM_s8GetIndex(Copy_Id);
    if (idx < 0) return;

    TIM_RegDef_t *t = TIM_Reg[idx];

    SET_BIT(t->EGR, TIM_EGR_UG);    /* Force an update event: loads PSC/ARR/CCR into shadow registers */
    CLR_BIT(t->SR,  TIM_SR_UIF);    /* UG sets UIF, clear it to avoid a spurious interrupt */
    SET_BIT(t->CR1, TIM_CR1_CEN);   /* Start counting */
}

/*===============================< TIM_voidStop >==========================*/
void TIM_voidStop(TIM_Id_t Copy_Id)
{
    int8_t idx = TIM_s8GetIndex(Copy_Id);
    if (idx < 0) return;

    CLR_BIT(TIM_Reg[idx]->CR1, TIM_CR1_CEN);
}

/*===============================< TIM_voidSetCaptureCompareValue >========
 * Writes the CCR value of the selected channel (duty cycle in PWM mode) */
void TIM_voidSetCaptureCompareValue(TIM_Id_t Copy_Id, uint8_t Copy_Channel, uint32_t Copy_CCR)
{
    int8_t idx = TIM_s8GetIndex(Copy_Id);
    int8_t ch  = TIM_s8GetChannelIndex(Copy_Channel);
    if (idx < 0 || ch < 0) return;

    switch (ch)
    {
        case 0: TIM_Reg[idx]->CCR1 = Copy_CCR; break;
        case 1: TIM_Reg[idx]->CCR2 = Copy_CCR; break;
        case 2: TIM_Reg[idx]->CCR3 = Copy_CCR; break;
        case 3: TIM_Reg[idx]->CCR4 = Copy_CCR; break;
        default: break;
    }
}

/*===================< TIM_voidSetCaptureCompareMode >=====================
 * Selects the channel direction (CCxS, 2 bits):
 *   00 = Output
 *   01 = Input, mapped on TI1
 *   10 = Input, mapped on TI2
 *   11 = Input, mapped on TRC
 * For PWM use 0 (output). Call this before TIM_voidSetOutputCompareMode. */
void TIM_voidSetCaptureCompareMode(TIM_Id_t Copy_Id, uint8_t Copy_Channel, uint8_t Copy_Mode)
{
    int8_t idx = TIM_s8GetIndex(Copy_Id);
    int8_t ch  = TIM_s8GetChannelIndex(Copy_Channel);
    if (idx < 0 || ch < 0) return;

    /* CH1/CH2 live in CCMR1, CH3/CH4 live in CCMR2. Odd channels are shifted by 8 bits. */
    volatile uint32_t *ccmr  = (ch < 2) ? &TIM_Reg[idx]->CCMR1 : &TIM_Reg[idx]->CCMR2;
    uint8_t            shift = (ch % 2) * 8;

    *ccmr &= ~(0x3UL << shift);                              /* Clear the old CCxS value */
    *ccmr |=  ((uint32_t)(Copy_Mode & 0x3U) << shift);       /* Write the new one        */
}

/*===================< TIM_voidSetOutputCompareMode >======================
 * Sets OCxM (3 bits) and enables the CCR preload (OCxPE).
 *   PWM Mode 1 = 6 (110): output HIGH while CNT < CCR
 *   PWM Mode 2 = 7 (111): inverted */
void TIM_voidSetOutputCompareMode(TIM_Id_t Copy_Id, uint8_t Copy_Channel, uint8_t Copy_Mode)
{
    int8_t idx = TIM_s8GetIndex(Copy_Id);
    int8_t ch  = TIM_s8GetChannelIndex(Copy_Channel);
    if (idx < 0 || ch < 0) return;

    volatile uint32_t *ccmr  = (ch < 2) ? &TIM_Reg[idx]->CCMR1 : &TIM_Reg[idx]->CCMR2;
    uint8_t            shift = (ch % 2) * 8;

    *ccmr &= ~(0x7UL << (shift + 4));                         /* Clear the old OCxM value */
    *ccmr |=  ((uint32_t)(Copy_Mode & 0x7U) << (shift + 4));  /* Write the new OCxM value */
    *ccmr |=  (1UL << (shift + 3));                           /* OCxPE = 1 (CCR preload)  */
}

/*===================< TIM_voidEnableChannel >=============================
 * Sets CCxE: routes the channel output to the pin.
 * The GPIO pin must be configured as Alternate Function. */
void TIM_voidEnableChannel(TIM_Id_t Copy_Id, uint8_t Copy_Channel)
{
    int8_t idx = TIM_s8GetIndex(Copy_Id);
    int8_t ch  = TIM_s8GetChannelIndex(Copy_Channel);
    if (idx < 0 || ch < 0) return;

    SET_BIT(TIM_Reg[idx]->CCER, ch * 4);
}

/*===================< TIM_voidDisableChannel >============================*/
void TIM_voidDisableChannel(TIM_Id_t Copy_Id, uint8_t Copy_Channel)
{
    int8_t idx = TIM_s8GetIndex(Copy_Id);
    int8_t ch  = TIM_s8GetChannelIndex(Copy_Channel);
    if (idx < 0 || ch < 0) return;

    CLR_BIT(TIM_Reg[idx]->CCER, ch * 4);
}

/*===================< TIM_voidSetPolarity >===============================
 * Copy_Polarity: 0 = active high, 1 = active low (CCxP) */
void TIM_voidSetPolarity(TIM_Id_t Copy_Id, uint8_t Copy_Channel, uint8_t Copy_Polarity)
{
    int8_t idx = TIM_s8GetIndex(Copy_Id);
    int8_t ch  = TIM_s8GetChannelIndex(Copy_Channel);
    if (idx < 0 || ch < 0) return;

    if (Copy_Polarity == 0) { CLR_BIT(TIM_Reg[idx]->CCER, ch * 4 + 1); }
    else                    { SET_BIT(TIM_Reg[idx]->CCER, ch * 4 + 1); }
}

/*===================< TIM_voidSetPwmFrequency >===========================
 * Calculates PSC and ARR from the requested frequency (in Hz) and applies them.
 * Takes into account the counter width (16/32-bit) and center-aligned mode
 * (in center-aligned mode the counter counts up and down, so the output
 * frequency is half for the same ARR). */
void TIM_voidSetPwmFrequency(TIM_Id_t Copy_Id, uint32_t Copy_Hz)
{
    int8_t idx = TIM_s8GetIndex(Copy_Id);
    if (idx < 0 || Copy_Hz == 0) return;

    TIM_RegDef_t *t = TIM_Reg[idx];

    uint32_t ticks = TIM_CLK_HZ / Copy_Hz;              /* Timer ticks per PWM period */
    if (TIM_ModeCfg[idx] != EDGE_ALIGNED)
    {
        ticks /= 2;                                     /* Center-aligned: up + down = 2 x ARR */
    }
    if (ticks < 2) return;                              /* Requested frequency is too high */

    /* Smallest PSC that lets ARR fit in the counter width */
    uint32_t psc = TIM_u8Is32Bit(idx) ? 0UL : (ticks / 65536UL);
    uint32_t arr = (ticks / (psc + 1UL)) - 1UL;

    t->PSC = psc;
    t->ARR = arr;
    SET_BIT(t->EGR, TIM_EGR_UG);                        /* Apply the new values immediately */
}

/*===================< TIM_voidSetDuty >===================================
 * Sets the duty cycle in percent (0..100), based on the current ARR value */
void TIM_voidSetDuty(TIM_Id_t Copy_Id, uint8_t Copy_Channel, uint8_t Copy_Percent)
{
    int8_t idx = TIM_s8GetIndex(Copy_Id);
    if (idx < 0) return;

    if (Copy_Percent > 100) Copy_Percent = 100;

    uint64_t period = (uint64_t)TIM_Reg[idx]->ARR + 1ULL;
    uint32_t ccr    = (uint32_t)((period * Copy_Percent) / 100ULL);

    TIM_voidSetCaptureCompareValue(Copy_Id, Copy_Channel, ccr);
}