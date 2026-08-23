/***************************************************
 * Author: khaled elwan
 * Date: 22/8/2026
 * Version: 1.0
 * Description: EXTI_program.c
 ***************************************************/


 /********************************< LIB ******************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*********************************< MCAL *****************************/
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"         
#include "GPIO_private.h"

Std_ReturnType EXTI_EnableLine(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionState = E_NOT_OK;
    if(Copy_Line < ETI_LINES_Count)
    {
        SET_BIT(EXTI_IMR, Copy_Line);
    } 
    else
    {
        Local_FunctionState = E_NOT_OK;
    }
    return Local_FunctionState;
}

Std_ReturnType EXTI_DisableLine(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionState = E_NOT_OK;
    if(Copy_Line < ETI_LINES_Count)
    {
        CLR_BIT(EXTI_IMR, Copy_Line);
    } 
    else
    {
        Local_FunctionState = E_NOT_OK;
    }
    return Local_FunctionState;
}


Std_ReturnType EXTI_SetTrigger(u8 Copy_Line, u8 Copy_Trigger)
{
    Std_ReturnType Local_FunctionState = E_NOT_OK;
    if(Copy_Line < ETI_LINES_Count)
    {
        switch(Copy_Trigger)
        {
            case 0: //Rising Edge
                SET_BIT(EXTI_RTSR, Copy_Line);
                CLR_BIT(EXTI_FTSR, Copy_Line);
                break;
            case 1: //Falling Edge
                CLR_BIT(EXTI_RTSR, Copy_Line);
                SET_BIT(EXTI_FTSR, Copy_Line);
                break;
            case 2: //Both Edges
                SET_BIT(EXTI_RTSR, Copy_Line);
                SET_BIT(EXTI_FTSR, Copy_Line);
                break;
            default:
                Local_FunctionState = E_NOT_OK;
                break;
        }
    } 
    else
    {
        Local_FunctionState = E_NOT_OK;
    }
    return Local_FunctionState;
}


Std_ReturnType EXTI_SelectPort(u8 Copy_Line, u8 Copy_Port)
{
    Std_ReturnType Local_FunctionState = E_NOT_OK;
    u8 Reg_Num = Copy_Line / 4;
    u8 Reg_Index = Copy_Line % 4;
    if(Copy_Line < ETI_LINES_Count   &&   Copy_Port < GPIO_PORTS_Count)
    {
        switch(Copy_Port)
        {
            case 0: //PORTA
                SYSCFG_EXTICR[Reg_Num] &= ~(0x000F << (Reg_Index * 4));
                break;
            case 1: //PORTB
                SYSCFG_EXTICR[Reg_Num] &= ~(0x000F << (Reg_Index * 4));
                SYSCFG_EXTICR[Reg_Num] |= (0x0001 << (Reg_Index * 4));
                break;
            case 2: //PORTC
                SYSCFG_EXTICR[Reg_Num] &= ~(0x000F << (Reg_Index * 4));
                SYSCFG_EXTICR[Reg_Num] |= (0x0002 << (Reg_Index * 4));
                break;
            default:
                Local_FunctionState = E_NOT_OK;
                break;
        }
    } 
    else
    {
        Local_FunctionState = E_NOT_OK;
    }
    return Local_FunctionState;
}


Std_ReturnType EXTI_ClearPendingFlag(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionState = E_NOT_OK;
    if(Copy_Line < ETI_LINES_Count)
    {
        SET_BIT(EXTI_PR, Copy_Line);
    } 
    else
    {
        Local_FunctionState = E_NOT_OK;
    }
    return Local_FunctionState;
}