/***************************************************
 * Author: khaled elwan
 * Date: 30/4/2026
 * Version: 1.0
 * Description: GPIO_interface.h
 ***************************************************/ 
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


 /***************************< PORTS >************************************************/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4

/***************************< PINS BITS >********************************************/
#define GPIO_PIN_0  0
#define GPIO_PIN_1  1
#define GPIO_PIN_2  2
#define GPIO_PIN_3  3
#define GPIO_PIN_4  4
#define GPIO_PIN_5  5
#define GPIO_PIN_6  6   
#define GPIO_PIN_7  7
#define GPIO_PIN_8  8
#define GPIO_PIN_9  9
#define GPIO_PIN_10 10
#define GPIO_PIN_11 11
#define GPIO_PIN_12 12
#define GPIO_PIN_13 13
#define GPIO_PIN_14 14
#define GPIO_PIN_15 15

/*************************< MODES >************************************************/
#define GPIO_MODE_INPUT  0b00
#define GPIO_MODE_OUTPUT 0b01
#define GPIO_MODE_AF     0b10
#define GPIO_MODE_ANALOG 0b11

/*************************< OUTPUT TYPES >***********************************************/
#define GPIO_OUTPUT_TYPE_PUSH_PULL 0b00
#define GPIO_OUTPUT_TYPE_OPEN_DRAIN 0b01

/*************************< OUTPUT SPEEDS >***********************************************/
#define GPIO_OUTPUT_SPEED_LOW 0b00
#define GPIO_OUTPUT_SPEED_MEDIUM 0b01
#define GPIO_OUTPUT_SPEED_HIGH 0b10
#define GPIO_OUTPUT_SPEED_VERY_HIGH 0b11

/*************************< PULL UP DOWN RESISTORS >***********************************************/
#define GPIO_PULL_UP_DOWN_NONE 0b00
#define GPIO_PULL_UP_DOWN_PULL_UP 0b01
#define GPIO_PULL_UP_DOWN_PULL_DOWN 0b10    
#define GPIO_PULL_UP_DOWN_PULL_UP_DOWN 0b11

/***********************< PIN VALUES >************************************/
#define GPIO_PIN_VALUE_LOW 0
#define GPIO_PIN_VALUE_HIGH 1





/**
 * @brief: Set pin mode
 * This function sets the mode of a specific GPIO pin on a specified port. It takes the port ID, pin ID, and mode as parameters, identifies the correct register to modify based on the port ID, and then updates the mode bits for the specified pin accordingly. The function returns a status indicating whether the operation was successful or not, allowing the caller to handle any potential errors in configuring the
 * GPIO pin mode. This is a fundamental function for configuring the behavior of GPIO pins, enabling them to operate as inputs, outputs, alternate functions, or in analog mode based on the requirements of the application.
 * @param Copy_u8PortId: The ID of the GPIO port (e.g., PORTA, PORTB, etc.)
 * @param Copy_u8PinId: The ID of the GPIO pin (e.g., GPIO_PIN_0, GPIO_PIN_1, etc.)
 * @param Copy_u8Mode: The mode to set for the GPIO pin (e.g., GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_AF, GPIO_MODE_ANALOG).
 * @return Std_ReturnType: A status indicating the success or failure of the operation (e.g., E_OK, E_NOT_OK).
 * @note - The function uses bit manipulation to clear the existing mode bits for the specified pin and then sets the
 */
Std_ReturnType GPIO_SetPinMode(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Mode);

/**
 * @brief: Set pin output type
 * This function sets the output type of a specific GPIO pin on a specified port. It takes the port ID, pin ID, and output type as parameters, identifies the correct register to modify based on the port ID, and then updates the output type bits for the specified pin accordingly. The function
 * returns a status indicating whether the operation was successful or not, allowing the caller to handle any potential errors in configuring the GPIO pin output type. This function is essential for defining how the GPIO pin drives its output signal, whether it is in push-pull mode or open-drain mode, which can affect the behavior of the pin and its compatibility with external devices or circuits.
 * @param Copy_u8PortId: The ID of the GPIO port (e.g., PORTA, PORTB, etc.)
 * @param Copy_u8PinId: The ID of the GPIO pin (e.g., GPIO_PIN_0, GPIO_PIN_1, etc.)
 * @param Copy_u8OutputType: The output type to set for the GPIO pin (e.g., GPIO_OUTPUT_TYPE_PUSH_PULL, GPIO_OUTPUT_TYPE_OPEN_DRAIN).
 * @return Std_ReturnType: A status indicating the success or failure of the operation (e.g., E_OK, E_NOT_OK).
 */
Std_ReturnType GPIO_SetPinOutputType(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8OutputType);
/**
 * @brief: Set pin output speed
 * This function sets the output speed of a specific GPIO pin on a specified port. It takes the port ID, pin ID, and output speed as parameters, identifies the correct register to modify based        
 * on the port ID, and then updates the output speed bits for the specified pin accordingly. The function returns a status indicating whether the operation was successful or not, allowing the caller to handle any potential errors in configuring the GPIO pin output speed. This function is crucial for defining how quickly the GPIO pin can switch between high and low states, which can be important for applications that require fast signal transitions or high-frequency communication.
 * @param Copy_u8PortId: The ID of the GPIO port (e.g., PORTA, PORTB, etc.)
 * @param Copy_u8PinId: The ID of the GPIO pin (e.g., GPIO_PIN_0, GPIO_PIN_1, etc.)
 * @param Copy_u8OutputSpeed: The output speed to set for the GPIO pin (e.g., GPIO_OUTPUT_SPEED_LOW, GPIO_OUTPUT_SPEED_MEDIUM, GPIO_OUTPUT_SPEED_HIGH, GPIO_OUTPUT_SPEED_VERY_HIGH).
 * @return Std_ReturnType: A status indicating the success or failure of the operation (e.g., E_OK, E_NOT_OK).  
 */
Std_ReturnType GPIO_SetPinOutputSpeed(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8OutputSpeed);
/**
 * @brief: Set pin pull-up/pull-down
 * This function sets the pull-up or pull-down configuration of a specific GPIO pin on a specified port. It takes the port ID, pin ID, and pull-up/pull-down configuration as parameters, identifies the correct register to modify based on the port ID, and then updates the pull-up/pull-down bits for the specified pin accordingly. The function returns a status indicating whether the operation was successful'
 * or not, allowing the caller to handle any potential errors in configuring the GPIO pin pull-up/pull-down settings. This function is important for defining the default state of the GPIO pin when it is configured as an input, ensuring that it does not float and can reliably read external signals.
 * @param Copy_u8PortId: The ID of the GPIO port (e.g., PORTA, PORTB, etc.)
 * @param Copy_u8PinId: The ID of the GPIO pin (e.g., GPIO_PIN_0, GPIO_PIN_1, etc.)
 * @param Copy_u8PullUpDown: The pull-up/pull-down configuration to set for the GPIO pin (e.g., GPIO_PULL_UP_DOWN_NONE, GPIO_PULL_UP_DOWN_PULL_UP, GPIO_PULL_UP_DOWN_PULL_DOWN).
 * @return Std_ReturnType: A status indicating the success or failure of the operation (e.g., E_OK, E_NOT_OK).
 */
Std_ReturnType GPIO_SetPinPullUpDown(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PullUpDown);  

/**
 * @brief: Get pin value
 * This function retrieves the current value of a specific GPIO pin on a specified port. It takes the port ID, pin ID, and a pointer to store the retrieved pin value as parameters. The function identifies the correct register to read based on the port ID, reads the input data register for the specified pin, and stores the value in the provided pointer. The function returns a status indicating whether the operation was successful or not, allowing the caller to handle any potential errors in reading the GPIO pin value
 * @param Copy_u8PortId: The ID of the GPIO port (e.g., PORTA, PORTB, etc.)
 * @param Copy_u8PinId: The ID of the GPIO pin (e.g., GPIO_PIN_0, GPIO_PIN_1, etc.)
 * @param Copy_pu8PinValue: A pointer to a variable where the retrieved pin
 * value will be stored.
 * @return Std_ReturnType: A status indicating the success or failure of the operation (e.g., E_OK, E_NOT_OK).
 */
Std_ReturnType GPIO_GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8* Copy_pu8PinReturnValue);


/**
 * @brief: Set pin value
 * This function sets the output value of a specific GPIO pin on a specified port. It takes the port ID, pin ID, and a pointer to the value to be set as parameters. The function identifies the correct register to modify based on the port ID, updates the output data register for the
 * specified pin with the provided value, and returns a status indicating whether the operation was successful or not. This function is essential for controlling the state of GPIO pins configured as outputs, allowing the application to drive signals high or low as needed.
 * @param Copy_u8PortId: The ID of the GPIO port (e.g., PORTA, PORTB, etc.)
 * @param Copy_u8PinId: The ID of the GPIO pin (e.g., GPIO_PIN_0, GPIO_PIN_1, etc.)
 * @param Copy_pu8PinValue: A pointer to the value to be set for the GPIO pin (e.g., GPIO_HIGH, GPIO_LOW).
 * @return Std_ReturnType: A status indicating the success or failure of the operation (e
 */

Std_ReturnType GPIO_SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_pu8PinValue);

















#endif
