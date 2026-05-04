/*****************< LIB >**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************< MCAL >**************************************/
/****< RCC>****/
#include "RCC_interface.h"
/****< GPIO>****/
#include "GPIO_interface.h"

/*****************< APP >**************************************/
u8 buttton ;
int main(void)
{
    /* Initialize the system clock */
    RCC_InitSysClock();
    
    /* Enable the clock for GPIOC peripheral */
    RCC_EnablePeripheralClock( RCC_AHB1_BUS , RCC_AHB1ENR_GPIOC_EN_BIT);
    /* Configure PC13 pin as output */
    GPIO_SetPinMode( PORTC, GPIO_PIN_13, GPIO_MODE_OUTPUT);
    /* Configure PC13 pin as push pull output */
    GPIO_SetPinOutputType( PORTC, GPIO_PIN_13,GPIO_OUTPUT_TYPE_PUSH_PULL );
    /* Configure PC13 pin as high speed output */
    GPIO_SetPinOutputSpeed( PORTC, GPIO_PIN_13, GPIO_OUTPUT_SPEED_LOW );
    /* Configure PC13 pin with pull-up resistor */
    GPIO_SetPinPullUpDown( PORTC, GPIO_PIN_13, GPIO_PULL_UP_DOWN_PULL_UP );



    /* Enable the clock for GPIOA peripheral */
    RCC_EnablePeripheralClock( RCC_AHB1_BUS , RCC_AHB1ENR_GPIOA_EN_BIT);
    /* Configure PA0 pin as input */
    GPIO_SetPinMode( PORTA, GPIO_PIN_0, GPIO_MODE_INPUT);
    
    /* Configure PA0 pin as high speed output */
    GPIO_SetPinOutputSpeed( PORTA, GPIO_PIN_0, GPIO_OUTPUT_SPEED_LOW );
    /* Configure PA0 pin with pull-up resistor */
    GPIO_SetPinPullUpDown( PORTA, GPIO_PIN_0, GPIO_PULL_UP_DOWN_PULL_UP );

    while (1) 
    {
      GPIO_GetPinValue(PORTA, GPIO_PIN_0, &buttton);
        if (buttton == GPIO_PIN_VALUE_HIGH)
        {
            GPIO_SetPinValue(PORTC, GPIO_PIN_13, GPIO_PIN_VALUE_LOW);
        }
        else
        {
            GPIO_SetPinValue(PORTC, GPIO_PIN_13, GPIO_PIN_VALUE_HIGH);
        }
    }
    
    return 0;
}