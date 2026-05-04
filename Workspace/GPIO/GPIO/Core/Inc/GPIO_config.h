/***************************************************
 * Author: khaled elwan
 * Date: 30/4/2026
 * Version: 1.0
 * Description: GPIO_config.h
 ***************************************************/ 
#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

#include "GPIO_interface.h"




/*


/****************************< PIN CONFIG >**********************************************/
/** 
 * @brief The configuration parameters for a GPIO pin MODE (input/output/alternate function/analog)
 * @note - GPIO_MODE_INPUT: Configures the pin as an input, allowing it to read external signals.
 * - GPIO_MODE_OUTPUT: Configures the pin as an output, enabling it to provide or receive signals.
 * - GPIO_MODE_AF: Configures the pin as an alternate function, allowing it to perform specific functions based on the selected alternate function. 
 * - GPIO_MODE_ANALOG: Configures the pin in analog mode, allowing it to be used for analog input or output operations, such as interfacing with ADCs or DACs.
 * - The mode of the pin determines its behavior and how it interacts with external signals, making it a crucial aspect of GPIO configuration for various applications.
 * @code
 * #define PIN_MODE           GPIO_MODE_OUTPUT
 * #define PIN_MODE           GPIO_MODE_INPUT
 * #define PIN_MODE           GPIO_MODE_AF
 * #define PIN_MODE           GPIO_MODE_ANALOG
 *
 * @endcode
 */

#define PIN_MODE            GPIO_MODE_OUTPUT

/** 
 * @brief The configuration parameters for a GPIO pin OUTPUT TYPE (push-pull/open-drain)
 * @note - GPIO_OUTPUT_TYPE_PUSH_PULL: Configures the pin as a push-pull output, allowing it to drive the output high or low actively. This is the most common output type
 * - GPIO_OUTPUT_TYPE_OPEN_DRAIN: Configures the pin as an open-drain output, allowing it to only drive the output low. When the pin is not driving low, it is effectively in a high-impedance state, which can be useful for certain applications such as I2C communication or when multiple devices share the same line.
 * - The output type of the pin determines how it drives the output signal, which can be important for ensuring proper operation and compatibility with external devices or circuits.
 * - The choice between push-pull and open-drain output types depends on the specific requirements of the application and the nature of the signals being driven.   
 * @code
 * #define PIN_OUTPUT_TYPE     GPIO_OUTPUT_TYPE_PUSH_PULL
 * #define PIN_OUTPUT_TYPE     GPIO_OUTPUT_TYPE_OPEN_DRAIN
 * 
 * @endcode
 */

#define PIN_OUTPUT_TYPE     GPIO_OUTPUT_TYPE_PUSH_PULL

/** 
 * @brief The configuration parameters for a GPIO pin OUTPUT SPEED (low/medium/high/very high)
 * @note - GPIO_OUTPUT_SPEED_LOW: Configures the pin for low-speed output, which is suitable for applications that do not require fast switching and can help reduce power consumption and electromagnetic interference (EMI).
 * - GPIO_OUTPUT_SPEED_MEDIUM: Configures the pin for medium-speed output, which provides a balance between switching speed and power consumption, making it suitable for general-purpose applications.
 * - GPIO_OUTPUT_SPEED_HIGH: Configures the pin for high-speed output, which allows for faster switching and is suitable for applications that require high-frequency signals or fast data transfer, but it may increase power
 * consumption and EMI.
 * - The output speed of the pin determines how quickly it can switch between high and low states, which can be important for applications that require fast signal transitions or high-frequency communication. The choice of output speed should be based on the specific requirements of the application, taking into consideration factors such as power consumption, EMI, and the nature of the signals being driven.
 * @code 
 * #define PIN_OUTPUT_SPEED    GPIO_OUTPUT_SPEED_LOW
 * #define PIN_OUTPUT_SPEED    GPIO_OUTPUT_SPEED_MEDIUM
 * #define PIN_OUTPUT_SPEED    GPIO_OUTPUT_SPEED_HIGH       
 * 
 * @endcode
 */ 
#define PIN_OUTPUT_SPEED    GPIO_OUTPUT_SPEED_LOW



/** 
 * @brief The configuration parameters for a GPIO pin PULL-UP/PULL-DOWN (none/pull-up/pull-down)
 * @note - GPIO_PULL_UP_DOWN_NONE: Configures the pin with no pull-up or pull-down resistors, leaving it in a floating state when not driven externally. This can be suitable for applications where the pin will always be driven by an external signal, but it may lead to unpredictable behavior if the pin is left floating.
 * - GPIO_PULL_UP_DOWN_PULL_UP: Configures the          
 * pin with an internal pull-up resistor, which pulls the pin to a high state when it is not driven externally. This can help ensure a defined logic level and prevent floating inputs, making it suitable for applications where the pin may be left unconnected or driven by an open-drain output.
 * - GPIO_PULL_UP_DOWN_PULL_DOWN: Configures the pin with an internal pull-down resistor
 * that pulls the pin to a low state when it is not driven externally. This can help ensure a defined logic level and prevent floating inputs, making it suitable for applications where the pin may be left unconnected or driven by an open-drain output.
 * - The pull-up/pull-down configuration of the pin determines how it behaves when not driven by an external signal, which can be important for ensuring reliable operation and preventing unpredictable behavior due to floating inputs. The choice of pull-up/pull-down configuration should be based on the specific requirements of the application and the nature of the signals being interfaced with the pin.
 * @code
 * #define PIN_PULL_UP_DOWN    GPIO_PULL_UP_DOWN_NONE
 * #define PIN_PULL_UP_DOWN    GPIO_PULL_UP_DOWN_PULL_UP            
 * #define PIN_PULL_UP_DOWN    GPIO_PULL_UP_DOWN_PULL_DOWN
 * #define PIN_PULL_UP_DOWN    GPIO_PULL_UP_DOWN_PULL_UP_DOWN
 * 
 * @endcode
 */
#define PIN_PULL_UP_DOWN    GPIO_PULL_UP_DOWN_NONE
















#endif