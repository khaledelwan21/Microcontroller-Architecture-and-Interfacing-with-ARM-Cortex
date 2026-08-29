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



/***************************, Global Variables ******************** */
static void (*pf_Single)(void)   = NULL;
static u32  g_u32TargetTime_Single = 0;
static volatile u32 g_u32MsTicks = 0;
static void (*pf_Periodic)(void) = NULL;
static u32  g_u32Interval_Periodic   = 0;
static u32  g_u32TargetTime_Periodic = 0;

/***************************< Functions *****************************/
void STK_voidInit(void)
{
    STK->CTRL &=~ STK_ENABLE ; // Disable SysTick during initialization

    #if STK_CLK_SOURCE == STK_AHB
        STK->CTRL |= STK_CLKSOURCE; // Set clock source to AHB
    #elif STK_CLK_SOURCE == STK_AHB_DIV_8
        STK->CTRL &=~ STK_CLKSOURCE; // Set clock source to AHB/8
    #else
        #error "Invalid STK_CLK_SOURCE configuration"
    #endif

    #if STK_CTRL_INTERRUPT_STATUS == STK_CTRL_INTERRUPT_ENABLE
        STK->CTRL |= STK_TICKINT; // Enable SysTick interrupt
    #elif STK_CTRL_INTERRUPT_STATUS == STK_CTRL_INTERRUPT_DISABLE
        STK->CTRL &=~ STK_TICKINT; // Disable SysTick interrupt
    #else
        #error "Invalid STK_CTRL_INTERRUPT_ENABLE configuration"
    #endif  

    u32 Local_TicksPerMs = (u32)(STK_GetAHBFrequency() / 1000);
    STK->LOAD = Local_TicksPerMs - 1;
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


/*static void STK_delay_1ms(u32 Num_Ticks, u32 Local_Counter) //void STK_delay_1ms(void)
{   
    while (Local_Counter != 0)
    {
    STK->LOAD = Num_Ticks - 1; // Set reload value
    STK->VAL = 0; // Clear current value
    CLR_BIT(STK->CTRL, STK_TICKINT); // Disable SysTick interrupt
    STK->CTRL |= STK_ENABLE; // Enable SysTick
    while ((STK->CTRL & STK_COUNTFLAG) == 0); // Wait until count flag is set
    STK->CTRL &=~ STK_ENABLE; // Disable SysTick
    Local_Counter--;
    }
}*/
u32 STK_delay_ms(u32 Copy_u32DelayTime_ms)
{
    u32 Local_StartTime = STK_Millis(); // Get current time
    
    while ((STK_Millis() - Local_StartTime) < Copy_u32DelayTime_ms)  // Wait until the specified delay time is reached
        {
             __WFI(); // Wait for interrupt
        }

    return 0;
}

u32 STK_Millis(void)
{
    return g_u32MsTicks;
}

Std_ReturnType STK_SetIntervalSingle(void (*Copy_CallBackFunc)(void), u32 Copy_u32DelayTime_ms)
{
    pf_Single = Copy_CallBackFunc;
    g_u32TargetTime_Single = STK_Millis() + Copy_u32DelayTime_ms; 
    return E_OK;
}

Std_ReturnType STK_SetIntervalPeriodic(void (*Copy_CallBackFunc)(void), u32 Copy_u32DelayTime_ms)
{
    pf_Periodic = Copy_CallBackFunc ;
    g_u32Interval_Periodic = Copy_u32DelayTime_ms;  
    g_u32TargetTime_Periodic = STK_Millis() + Copy_u32DelayTime_ms ; 
    return E_OK;
}

void SysTick_Handler(void)
{
    g_u32MsTicks++;

    if (pf_Single != NULL && g_u32MsTicks >= g_u32TargetTime_Single)
    {
        pf_Single();
        pf_Single = NULL;
    }
    if( pf_Periodic != NULL && g_u32MsTicks >= g_u32TargetTime_Periodic)
    {
        pf_Periodic();
        g_u32TargetTime_Periodic = g_u32MsTicks + g_u32Interval_Periodic; 
    }
}