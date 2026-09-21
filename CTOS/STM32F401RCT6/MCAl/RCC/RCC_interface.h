/***************************************************
 * Author: khaled elwan
 * Date: 10/4/2026
 * Version: 1.0
 * Description: RCC_interface.h
 ***************************************************/           
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


#include "STD_TYPES.h"
#include "RCC_private.h"
#include "RCC_config.h"


#define RCC_AHB1_BUS		 0
#define RCC_AHB2_BUS		 1
#define RCC_APB1_BUS 		 2
#define RCC_APB2_BUS 		 3



/**
 * @defgroup RCC_AHB1ENR_BITS AHB1 Peripheral Clock Enable Bits
 * @brief Bits used to enable the clocks for peripherals connected to the AHB1 bus in the RCC_AHB1ENR register.
 */

#define RCC_AHB1ENR_DMA2_EN_BIT           22    
#define RCC_AHB1ENR_DMA1_EN_BIT           21
#define RCC_AHB1ENR_CRC_EN_BIT            12
#define RCC_AHB1ENR_GPIOH_EN_BIT          7
#define RCC_AHB1ENR_GPIOE_EN_BIT          4
#define RCC_AHB1ENR_GPIOD_EN_BIT          3
#define RCC_AHB1ENR_GPIOC_EN_BIT          2
#define RCC_AHB1ENR_GPIOB_EN_BIT          1
#define RCC_AHB1ENR_GPIOA_EN_BIT          0

/**
 * @defgroup RCC_AHB2ENR_BITS AHB2 Peripheral Clock Enable Bits
 * @brief Bits used to enable the clocks for peripherals connected to the AHB2 bus in
 */

#define RCC_AHB2ENR_OTGFS_EN_BIT          7

/**
 * @defgroup RCC_APB1ENR_BITS APB1 Peripheral Clock Enable Bits
 * @brief Bits used to enable the clocks for peripherals connected to the APB1 bus in
 */
#define RCC_APB1ENR_PWREN_BIT            28
#define RCC_APB1ENR_I2C3EN_BIT           23
#define RCC_APB1ENR_I2C2EN_BIT           22
#define RCC_APB1ENR_I2C1EN_BIT           21
#define RCC_APB1ENR_UART2EN_BIT          17
#define RCC_APB1ENR_SPI3EN_BIT           15
#define RCC_APB1ENR_SPI2EN_BIT           14
#define RCC_APB1ENR_WWDGEN_BIT           11
#define RCC_APB1ENR_TIM5EN_BIT           3
#define RCC_APB1ENR_TIM4EN_BIT           2
#define RCC_APB1ENR_TIM3EN_BIT           1
#define RCC_APB1ENR_TIM2EN_BIT           0


#/**
 * @defgroup RCC_APB2ENR_BITS APB2 Peripheral Clock Enable Bits
 * @brief Bits used to enable the clocks for peripherals connected to the APB2 bus in
 */
#define RCC_APB2ENR_TIM11EN_BIT          18
#define RCC_APB2ENR_TIM10EN_BIT          17
#define RCC_APB2ENR_TIM9EN_BIT           16
#define RCC_APB2ENR_SYSCFGEN_BIT         14
#define RCC_APB2ENR_SPI1EN_BIT           12
#define RCC_APB2ENR_USART6EN_BIT         5
#define RCC_APB2ENR_USART1EN_BIT         4
#define RCC_APB2ENR_TIM1EN_BIT           0

/**
 * @defgroup RCC_SYS_CLK_SOURCES System Clock Sources
 * @brief Constants used to select the system clock source in the RCC_CFGR register.
 */

Std_ReturnType RCC_InitSysClock(void);
/** 
* @defgroup RCC_EnablePeripheralClock RCC_EnablePeripheralClock
* @brief Function to enable a peripheral clock
**/
Std_ReturnType RCC_EnablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);

/**
* @defgroup RCC_DisablePeripheralClock RCC_DisablePeripheralClock
* @brief Function to disable a peripheral clock
* */
Std_ReturnType RCC_DisablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
/**
* @defgroup RCC_GetFrequency RCC_GetFrequency
* @brief Function to get the frequency
* */
Std_ReturnType RCC_GetFrequency(u32 *Copy_pu32Frequency);

#endif /* RCC_INTERFACE_H */   
 