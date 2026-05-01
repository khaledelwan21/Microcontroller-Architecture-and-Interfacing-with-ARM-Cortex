/***************************************************
 * Author: khaled elwan
 * Date: 30/4/2026
 * Version: 1.0
 * Description: GPIO_program.c
 ***************************************************/ 

/*****************< LIB ******************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*****************< MCAL ****************************/
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"         


Std_ReturnType GPIO_SetPinMode(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Mode)
{
    Std_ReturnType Local_FunctionState = E_NOT_OK;

    switch (Copy_u8PortId)
    {
    case PORTA:
        GPIOA_MODER &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the mode bits for the specified pin
        GPIOA_MODER |= (Copy_u8Mode << (Copy_u8PinId * 2)); // Set the mode bits for the specified pin
         Local_FunctionState = E_OK;
        break;
    case PORTB:
        GPIOB_MODER &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the mode bits for the specified pin
        GPIOB_MODER |= (Copy_u8Mode << (Copy_u8PinId * 2)); // Set the mode bits for the specified pin
        break;
    case PORTC:
        GPIOC_MODER &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the mode bits for the specified pin
        GPIOC_MODER |= (Copy_u8Mode << (Copy_u8PinId * 2)); // Set the mode bits for the specified pin
        break;
    case PORTD:
        GPIOD_MODER &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the mode bits for the specified pin
        GPIOD_MODER |= (Copy_u8Mode << (Copy_u8PinId * 2)); // Set the mode bits for the specified pin
        break;
    case PORTE:
        GPIOE_MODER &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the mode bits for the specified pin
        GPIOE_MODER |= (Copy_u8Mode << (Copy_u8PinId * 2)); // Set the mode bits for the specified pin
        break;  
    default:
        Local_FunctionState = E_NOT_OK; 
        break;
    }

    return Local_FunctionState;
}

Std_ReturnType GPIO_SetPinOutputType(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8OutputType)
{
    Std_ReturnType Local_FunctionState = E_NOT_OK;  

    switch (Copy_u8PortId)
    {
    case PORTA:
        GPIOA_OTYPER &= ~(0b1 << Copy_u8PinId); // Clear the output type bit for the specified pin
        GPIOA_OTYPER |= (Copy_u8OutputType << Copy_u8PinId); // Set the output type bit for the specified pin
        Local_FunctionState = E_OK;
        break;
    case PORTB:
        GPIOB_OTYPER &= ~(0b1 << Copy_u8PinId); //                                                          
        GPIOB_OTYPER |= (Copy_u8OutputType << Copy_u8PinId); // Set the output type bit for the specified pin
        break;
    case PORTC:
        GPIOC_OTYPER &= ~(0b1 << Copy_u8PinId); // Clear the output type bit for the specified pin
        GPIOC_OTYPER |= (Copy_u8OutputType << Copy_u8PinId); // Set the output type bit for the specified pin
        break;
    case PORTD:
        GPIOD_OTYPER &= ~(0b1 << Copy_u8PinId); // Clear the output type bit for the specified pin
        GPIOD_OTYPER |= (Copy_u8OutputType << Copy_u8PinId); // Set the output type bit for the specified pin
        break;
    case PORTE:
        GPIOE_OTYPER &= ~(0b1 << Copy_u8PinId); // Clear the output type bit for the specified pin
        GPIOE_OTYPER |= (Copy_u8OutputType << Copy_u8PinId); // Set the output type bit for the specified pin
        break;  
    default:
        Local_FunctionState = E_NOT_OK;
        break;
    }

    return Local_FunctionState;
}   

Std_ReturnType GPIO_SetPinOutputSpeed(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8OutputSpeed)
{
    Std_ReturnType Local_FunctionState = E_NOT_OK;  

    switch (Copy_u8PortId)
    {
    case PORTA:
        GPIOA_OSPEEDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the output speed bits for the specified pin
        GPIOA_OSPEEDR |= (Copy_u8OutputSpeed << (Copy_u8PinId * 2)); // Set the output speed bits for the specified pin
        Local_FunctionState = E_OK;
        break;
    case PORTB:
        GPIOB_OSPEEDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the output speed bits for the specified pin
        GPIOB_OSPEEDR |= (Copy_u8OutputSpeed << (Copy_u8PinId * 2)); // Set the output speed bits for the specified pin
        break;
    case PORTC:
        GPIOC_OSPEEDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the output speed bits for the specified pin
        GPIOC_OSPEEDR |= (Copy_u8OutputSpeed << (Copy_u8PinId * 2)); // Set the output speed bits for the specified pin
        break;
    case PORTD:
        GPIOD_OSPEEDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the output speed bits for the specified pin
        GPIOD_OSPEEDR |= (Copy_u8OutputSpeed << (Copy_u8PinId * 2)); // Set the output speed bits for the specified pin
        break;
    case PORTE:
        GPIOE_OSPEEDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the output speed bits for the specified pin
        GPIOE_OSPEEDR |= (Copy_u8OutputSpeed << (Copy_u8PinId * 2)); // Set the output speed bits for the specified pin
        break;  
    default:
        Local_FunctionState = E_NOT_OK;
        break;
    }

    return Local_FunctionState; 
}

Std_ReturnType GPIO_SetPinPullUpPullDown(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PullUpPullDown)
{
    Std_ReturnType Local_FunctionState = E_NOT_OK;  

    switch (Copy_u8PortId)
    {
    case PORTA:
        GPIOA_PUPDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the pull-up/pull-down bits for the specified pin
        GPIOA_PUPDR |= (Copy_u8PullUpPullDown << (Copy_u8PinId * 2)); // Set the pull-up/pull-down bits for the specified pin
        Local_FunctionState = E_OK;
        break;
    case PORTB:
        GPIOB_PUPDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the pull-up/pull-down bits for the specified pin
        GPIOB_PUPDR |= (Copy_u8PullUpPullDown << (Copy_u8PinId * 2)); // Set the pull-up/pull-down bits for the specified pin
        break;
    case PORTC:
        GPIOC_PUPDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the pull-up/pull-down bits for the specified pin
        GPIOC_PUPDR |= (Copy_u8PullUpPullDown << (Copy_u8PinId * 2)); // Set the pull-up/pull-down bits for the specified pin
        break;
    case PORTD:
        GPIOD_PUPDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the pull-up/pull-down bits for the specified pin
        GPIOD_PUPDR |= (Copy_u8PullUpPullDown << (Copy_u8PinId * 2)); // Set the pull-up/pull-down bits for the specified pin
        break;
    case PORTE:
        GPIOE_PUPDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the pull-up/pull-down bits for the specified pin
        GPIOE_PUPDR |= (Copy_u8PullUpPullDown << (Copy_u8PinId * 2)); // Set the pull-up/pull-down bits for the specified pin
        break;  
    default:
        Local_FunctionState = E_NOT_OK;
        break;
    }

    return Local_FunctionState; 
}           
Std_ReturnType GPIO_SetPinPullUpDown(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PullUpDown)
{
    Std_ReturnType Local_FunctionState = E_NOT_OK;  

    switch (Copy_u8PortId)
    {
    case PORTA:
        GPIOA_PUPDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the pull-up/pull-down bits for the specified pin
        GPIOA_PUPDR |= (Copy_u8PullUpDown << (Copy_u8PinId * 2)); // Set the pull-up/pull-down bits for the specified pin
        Local_FunctionState = E_OK;
        break;
    case PORTB:
        GPIOB_PUPDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the pull-up/pull-down bits for the specified pin
        GPIOB_PUPDR |= (Copy_u8PullUpDown << (Copy_u8PinId * 2)); // Set the pull-up/pull-down bits for the specified pin
        break;
    case PORTC:
        GPIOC_PUPDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the pull-up/pull-down bits for the specified pin
        GPIOC_PUPDR |= (Copy_u8PullUpDown << (Copy_u8PinId * 2)); // Set the pull-up/pull-down bits for the specified pin
        break;
    case PORTD:
        GPIOD_PUPDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the pull-up/pull-down bits for the specified pin
        GPIOD_PUPDR |= (Copy_u8PullUpDown << (Copy_u8PinId * 2)); // Set the pull-up/pull-down bits for the specified pin
        break;
    case PORTE:
        GPIOE_PUPDR &= ~(0b11 << (Copy_u8PinId * 2)); // Clear the pull-up/pull-down bits for the specified pin
        GPIOE_PUPDR |= (Copy_u8PullUpDown << (Copy_u8PinId * 2)); // Set the pull-up/pull-down bits for the specified pin
        break;  
    default:
        Local_FunctionState = E_NOT_OK;
        break;
    }

    return Local_FunctionState;
}

Std_ReturnType GPIO_GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8* Copy_pu8PinValue)
{
    Std_ReturnType Local_FunctionState = E_NOT_OK;  

    switch (Copy_u8PortId)
    {
    case PORTA:
        *Copy_pu8PinValue = (GPIOA_IDR >> Copy_u8PinId) & 0b1; // Read the value of the specified pin and store it in the provided pointer
        Local_FunctionState = E_OK;
        break;
    case PORTB:
        *Copy_pu8PinValue = (GPIOB_IDR >> Copy_u8PinId) & 0b1; // Read the value of the specified pin and store it in the provided pointer
        break;
    case PORTC:
        *Copy_pu8PinValue = (GPIOC_IDR >> Copy_u8PinId) & 0b1; // Read the value of the specified pin and store it in the provided pointer
        break;
    case PORTD:
        *Copy_pu8PinValue = (GPIOD_IDR >> Copy_u8PinId) & 0b1; // Read the value of the specified pin and store it in the provided pointer
        break;
    case PORTE:
        *Copy_pu8PinValue = (GPIOE_IDR >> Copy_u8PinId) & 0b1; // Read the value of the specified pin and store it in the provided pointer
        break;  
    default:
        Local_FunctionState = E_NOT_OK;
        break;
    }

    return Local_FunctionState; 
}

Std_ReturnType GPIO_SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_pu8PinValue)
{
    Std_ReturnType Local_FunctionState = E_NOT_OK;  

    switch (Copy_u8PortId)
    {
    case PORTA:
        if (Copy_pu8PinValue == 0)
        {
            GPIOA_ODR &= ~(0b1 << Copy_u8PinId); // Clear the output data bit for the specified pin to set it low
        }
        else if ( Copy_pu8PinValue == 1)
        {
            GPIOA_ODR |= (0b1 << Copy_u8PinId); // Set the output data bit for the specified pin to set it high
        }
        Local_FunctionState = E_OK;
        break;
    case PORTB:
        if ( Copy_pu8PinValue == 0)
        {
            GPIOB_ODR &= ~(0b1 << Copy_u8PinId); // Clear the output data bit for the specified pin to set it low
        }
        else if ( Copy_pu8PinValue == 1)
        {
            GPIOB_ODR |= (0b1 << Copy_u8PinId); // Set the output data bit for the specified pin to set it high
        }
        break;
    case PORTC:
        if ( Copy_pu8PinValue == 0)
        {
            GPIOC_ODR &= ~(0b1 << Copy_u8PinId); // Clear the output data bit for the specified pin to set it low
        }
        else if ( Copy_pu8PinValue == 1)
        {
            GPIOC_ODR |= (0b1 << Copy_u8PinId); // Set the output data bit for the specified pin to set it high
        }
        break;
    case PORTD:
        if ( Copy_pu8PinValue == 0)
        {
            GPIOD_ODR &= ~(0b1 << Copy_u8PinId); // Clear the output data bit for the specified pin to set it low
        }
        else if ( Copy_pu8PinValue == 1)
        {
            GPIOD_ODR |= (0b1 << Copy_u8PinId); // Set the output data bit for the specified pin to set it high
        }
        break;
    case PORTE:
        if ( Copy_pu8PinValue == 0)
        {
            GPIOE_ODR &= ~(0b1 << Copy_u8PinId); // Clear the output data bit for the specified pin to set it low
        }
        else if ( Copy_pu8PinValue == 1)
        {
            GPIOE_ODR |= (0b1 << Copy_u8PinId); // Set the output data bit for the specified pin to set it high
        }
        break;  
    default:
        Local_FunctionState = E_NOT_OK;
        break;
    }   

    return Local_FunctionState; 
}   

