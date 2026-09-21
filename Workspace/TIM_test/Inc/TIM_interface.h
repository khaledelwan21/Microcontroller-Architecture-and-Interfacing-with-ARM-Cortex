/************************************************** 
* Author: Khaled Ahmed Elwan
* Date: 19/9/2026
* Version: 1.0
* Description: TIM_interface.h
***************************************************/
#ifndef TIM_INTERFACE_H
#define TIM_INTERFACE_H

/*************************< TIM_Id_t >*********************************************/
typedef enum {
    TIM_2,
    TIM_3,
    TIM_4,
    TIM_5,
    TIM_9,
    TIM_10,
    TIM_11
} TIM_Id_t;

/***************************< Channel >*********************************************/
#define CHANNEL_1   1
#define CHANNEL_2   2
#define CHANNEL_3   3
#define CHANNEL_4   4

/* Output compare modes (OCxM) */
#define output              0
#define TI1                 1
#define TI2                 2
#define TRC                 3

/* Output compare modes (OCxM) */
#define TIM_OC_FROZEN              0
#define TIM_OC_ACTIVE_ON_MATCH     1
#define TIM_OC_INACTIVE_ON_MATCH   2
#define TIM_OC_TOGGLE              3
#define TIM_OC_FORCE_INACTIVE      4
#define TIM_OC_FORCE_ACTIVE        5
#define TIM_OC_PWM_MODE1           6
#define TIM_OC_PWM_MODE2           7

/*************************< Base timer >**********************************/
void TIM_voidInit(TIM_Id_t Copy_Id);
void TIM_voidSetPrescaler(TIM_Id_t Copy_Id, u32 Copy_Psc);
void TIM_voidSetPeriod(TIM_Id_t Copy_Id, u32 Copy_Arr);
void TIM_voidStart(TIM_Id_t Copy_Id);
void TIM_voidStop(TIM_Id_t Copy_Id);

/*************************< Base timer >**********************************/
void TIM_voidSetCaptureCompareValue(TIM_Id_t Copy_Id, u8 Copy_Channel, u32 Copy_CCR);
void TIM_voidSetCaptureCompareMode(TIM_Id_t Copy_Id, u8 Copy_Channel, u8 Copy_Mode);
void TIM_voidSetOutputCompareMode(TIM_Id_t Copy_Id, u8 Copy_Channel, u8 Copy_Mode);

void TIM_voidEnableChannel(TIM_Id_t Copy_Id, u8 Copy_Channel);
void TIM_voidDisableChannel(TIM_Id_t Copy_Id, u8 Copy_Channel);
void TIM_voidSetPolarity(TIM_Id_t Copy_Id, u8 Copy_Channel, u8 Copy_Polarity);

/*************************< PWM helpers >*********************************/
void TIM_voidSetPwmFrequency(TIM_Id_t Copy_Id, u32 Copy_Hz);
void TIM_voidSetDuty(TIM_Id_t Copy_Id, u8 Copy_Channel, u8 Copy_Percent);



#endif