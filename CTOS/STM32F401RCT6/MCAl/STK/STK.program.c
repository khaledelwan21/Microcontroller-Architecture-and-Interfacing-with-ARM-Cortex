/***************************************************
 * Author: khaled elwan
 * Date: 24/8/2026
 * Version: 1.0
 * Description: STK_program.c
 ***************************************************/

/***************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***************************< MCAL *****************************/
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"
#include "RCC_interface.h"

void STK_voidInit(u32 Copy_u32Ticks)
{
    STK->CTRL &=~ STK_ENABLE ; // Disable SysTick during initialization

    #if STK_CLK_SOURCE == STK_AHB
        STK->CTRL |= STK_CLKSOURCE; // Set clock source to AHB
    #elif STK_CLK_SOURCE == STK_AHB_DIV_8
        STK->CTRL &=~ STK_CLKSOURCE; // Set clock source to AHB/8
    #else
        #error "Invalid STK_CLK_SOURCE configuration"
    #endif

    #if STK_CTRL_INTERRUPT_ENABLE == STK_CTRL_INTERRUPT_ENABLE
        STK->CTRL |= STK_TICKINT; // Enable SysTick interrupt
    #elif STK_CTRL_INTERRUPT_ENABLE == STK_CTRL_INTERRUPT_DISABLE
        STK->CTRL &=~ STK_TICKINT; // Disable SysTick interrupt
    #else
        #error "Invalid STK_CTRL_INTERRUPT_ENABLE configuration"
    #endif  

    if (Copy_u32Ticks > STK_Reload_MAX_Value)
    {
        // Handle error: Reload value exceeds maximum allowed value
        // You can choose to return an error code or assert here
        return;
    }
    STK->LOAD = Copy_u32Ticks - 1; // Set reload value
    STK->VAL = 0; // Clear current value
    STK->CTRL |= STK_ENABLE; // Enable SysTick
}


void STK_Stop(void)
{
    STK->CTRL &=~ STK_ENABLE; // Disable SysTick
}

void STK_Reset(void)
{
    STK->CTRL &=~ STK_ENABLE;   // Disable SysTick
    STK->VAL = 0;               // Clear current value
    STK->CTRL |= STK_ENABLE;    // Enable SysTick
}

u64 STK_GetAHBFrequency(void)
{
    u32 Local_u32Frequency = 0;
    
    if (RCC_GetFrequency(&Local_u32Frequency) == E_OK)
    {
        #if STK_CLK_SOURCE == STK_AHB_DIV_8
            return (Local_u32Frequency / 8);
        #elif STK_CLK_SOURCE == STK_AHB
            return Local_u32Frequency;
        #else
            #error "Invalid STK_CLK_SOURCE configuration"
        #endif
    }
    
    return 0; 
}
static u32 STK_GetRemainingTime(u32 Copy_u32Multiplier)
{
    u32 Local_u32Frequency = STK_GetAHBFrequency();
    
    if (Local_u32Frequency == 0)
    {
        return 0;
    }
    
    return (u32)(((u64)STK->VAL * Copy_u32Multiplier) / Local_u32Frequency);
}

u32 STK_GetRemainingTime_us(void)
{
    return STK_GetRemainingTime(1000000UL);
}

u32 STK_GetRemainingTime_ms(void)
{
    return STK_GetRemainingTime(1000UL);
}






