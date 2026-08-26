/***************************************************
 * Author: khaled elwan
 * Date: 24/8/2026
 * Version: 1.0
 * Description: STK_private.h
 **************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


#define STK_BASE_ADDRESS 0xE000E010U
typedef struct
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
}STK_Type;

#define STK ((STK_Type*)STK_BASE_ADDRESS)

#define STK_ENABLE 0x00000001
#define STK_TICKINT 0x00000002
#define STK_CLKSOURCE 0x00000004
#define STK_COUNTFLAG 0x00010000


#define STK_AHB_DIV_8 0
#define STK_AHB 1


#define STK_CTRL_INTERRUPT_ENABLE 1
#define STK_CTRL_INTERRUPT_DISABLE 0


#define STK_Reload_MAX_Value 0x00FFFFFF



#endif