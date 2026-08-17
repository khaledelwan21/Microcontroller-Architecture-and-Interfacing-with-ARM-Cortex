/***************************************************
 * Author: khaled elwan
 * Date: 17/8/2026
 * Version: 1.0
 * Description: NVIC_program.c
 ***************************************************/ 
 
 /****< LIB *****/
 #include  "STD_TYPES.h"
 #include  "BIT_MATH.h"
  
 /****< MCAL*****/
 
 #include "NVIC_interface.h"
 #include "NVIC_private.h"
 #include "NVIC_config.h"
 
 
 
 Std_ReturnType NVIC_EnableIRQ( IRQn_Type Copy_IRQn) 
 { 
	 Std_ReturnType Local_FunctionState = E_NOT_OK;
	 
	 switch (Copy_IRQn / 32)
    {
        case 0:
            NVIC_ISER0 = (1U << (Copy_IRQn % 32));
			Local_FunctionState = E_OK;
            break;

        case 1:
            NVIC_ISER1 = (1U << (Copy_IRQn % 32));
			Local_FunctionState = E_OK;
            break;

        case 2:
            NVIC_ISER2 = (1U << (Copy_IRQn % 32));
			Local_FunctionState = E_OK;
            break;

        default:	
            return  Local_FunctionState;
    }

    return Local_FunctionState;
	 
 }
 
 Std_ReturnType NVIC_DisableIRQ( IRQn_Type Copy_IRQn) 
 {
	 Std_ReturnType Local_FunctionState = E_NOT_OK;
	 
	 switch (Copy_IRQn / 32)
    {
        case 0:
            NVIC_ICER0 = (1U << (Copy_IRQn % 32));
			Local_FunctionState = E_OK;
            break;

        case 1:
            NVIC_ICER1 = (1U << (Copy_IRQn % 32));
			Local_FunctionState = E_OK;
            break;

        case 2:
            NVIC_ICER2 = (1U << (Copy_IRQn % 32));
			Local_FunctionState = E_OK;
            break;

        default:
            return  Local_FunctionState;
    }

    return Local_FunctionState;
	 
 }
 
 Std_ReturnType NVIC_SetPendingIRQ(IRQn_Type Copy_IRQn)
 {
	 Std_ReturnType Local_FunctionState = E_NOT_OK;
	 
	 switch (Copy_IRQn / 32)
    {
        case 0:
            NVIC_ISPR0 = (1U << (Copy_IRQn % 32));
			Local_FunctionState = E_OK;
            break;

        case 1:
            NVIC_ISPR1 = (1U << (Copy_IRQn % 32));
			Local_FunctionState = E_OK;
            break;

        case 2:
            NVIC_ISPR2 = (1U << (Copy_IRQn % 32));
			Local_FunctionState = E_OK;
            break;

        default:
            return  Local_FunctionState;
    }

    return Local_FunctionState;
 }
 
 Std_ReturnType NVIC_ClearPendingIRQ(IRQn_Type Copy_IRQn) 
 {
	 Std_ReturnType Local_FunctionState = E_NOT_OK;
	 
	 switch (Copy_IRQn / 32)
    {
        case 0:
            NVIC_ICPR0 = (1U << (Copy_IRQn % 32));
			Local_FunctionState = E_OK;
            break;

        case 1:
            NVIC_ICPR1 = (1U << (Copy_IRQn % 32));
			Local_FunctionState = E_OK;
            break;

        case 2:
            NVIC_ICPR2 = (1U << (Copy_IRQn % 32));
			Local_FunctionState = E_OK;
            break;

        default:
            return  Local_FunctionState;
    }

    return Local_FunctionState;
 }
 
 Std_ReturnType NVIC_GetPendingIRQ(IRQn_Type Copy_IRQn,u8 *Copy_ReturnPendingFlag) 
 {
	 Std_ReturnType Local_FunctionState = E_NOT_OK;
	 
	if(Copy_ReturnPendingFlag != NULL)
	{
	 switch (Copy_IRQn / 32)
    {
        case 0:
            *Copy_ReturnPendingFlag=GET_BIT(NVIC_ISPR0,Copy_IRQn % 32) ;
			Local_FunctionState = E_OK;
            break;

        case 1:
            *Copy_ReturnPendingFlag=GET_BIT(NVIC_ISPR1,Copy_IRQn % 32) ;
			Local_FunctionState = E_OK;
            break;

        case 2:
            *Copy_ReturnPendingFlag=GET_BIT(NVIC_ISPR2,Copy_IRQn % 32) ;
			Local_FunctionState = E_OK;
            break;

        default:
            return  Local_FunctionState;
    }
	}
    return Local_FunctionState;
 }
 
 Std_ReturnType NVIC_SetPriority(IRQn_Type Copy_IRQn, u32 priority) 
 {
	 
 }
 
 Std_ReturnType NVIC_GetPriority(IRQn_Type Copy_IRQn) 
 {
	 
	 
 }
