/******************************
 * Author: Khaled Elwan
 * Date: 10/4/2026
 * Version: 1.0
 * Description: RCC_program.c
 ******************************/

/****************************< LIB ************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"



/****************************< MCAL************************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

static void RCC_EnableHSE(void)
        {

        /* Configure HSE bypass mode */
        #if RCC_CLK_BYPASS == RCC_CRYSTAL_CLK

            SET_BIT(RCC_CR, RCC_CR_HSEBYP_BIT); // HSEBYP bit   

        #elif RCC_CLK_BYPASS == RCC_RC_CLK
        
            CLR_BIT(RCC_CR, RCC_CR_HSEBYP_BIT); // HSEBYP bit

        #else

            #error "Invalid HSE bypass mode configuration in RCC_config.h"

        #endif 

        /* Enable HSE */
        SET_BIT(RCC_CR, RCC_CR_HSEON_BIT); // HSEON bit
        /* Wait until HSE is ready */
        while (GET_BIT(RCC_CR, RCC_CR_HSERDY_BIT) == 0); // HSERDY bit
        /* Select HSE as system clock */
    
        }

Std_ReturnType RCC_InitSysClock(void)

{
    Std_ReturnType Local_FunctionState = E_NOT_OK;
    /**@brief: Initialize system clock
     * This function initializes the system clock based on the configuration defined in RCC_config.h. It checks the selected clock source (RCC_SYS_CLK) and configures the necessary registers to enable and stabilize the chosen clock source. If RCC_SYS_CLK is set to RCC_HSE, it will also configure the HSE bypass mode based on RCC_CLK_BYPASS. The function ensures that the selected clock source is ready before returning, allowing the microcontroller to operate with a stable system clock. This initialization is crucial for the proper functioning of the microcontroller and its peripherals, as it determines the timing and performance of the entire system.
     * @note
     * - The function first checks the value of RCC_SYS_CLK to determine which clock source to initialize. If RCC_SYS_CLK is set to RCC_HSE, it will configure the HSE bypass
     */
    #if RCC_SYS_CLK == RCC_HSE

        RCC_EnableHSE();
        RCC_CFGR &= ~(0x03 << RCC_CFGR_SW_BITS);
        RCC_CFGR |= (RCC_HSE << RCC_CFGR_SW_BITS); // Select HSE as system clock source
        while (((RCC_CFGR >> 2) & 0x03) != RCC_HSE);
        Local_FunctionState = E_OK;
        
    /** @brief: Select HSI as system clock 
     * If RCC_SYS_CLK is set to RCC_HSI, the function will enable the HSI (High-Speed Internal) oscillator and wait until it is ready before selecting it as the system clock source. The HSI is typically a 16 MHz internal RC oscillator that provides a stable clock source for the microcontroller. This option is often used in low-power applications or when an external crystal is not available. The function ensures that the HSI is properly enabled and stable before it is used as the system clock, which is crucial for the reliable operation of the microcontroller and its peripherals.
     * @note
     * - When RCC_SYS_CLK is set to RCC_HSI, the function will enable the HSI oscillator by setting the HSION bit in the RCC_CR register. It will then wait for the HSIRDY bit to be set, indicating that the HSI is stable and ready to be used as the system clock source. Once the HSI is ready, it will be selected as the system clock source in the RCC_CFGR register. This configuration allows the microcontroller to operate using the internal RC oscillator, which is suitable for applications that do not require high precision or when an external crystal is not available.
    */
    #elif RCC_SYS_CLK == RCC_HSI

        /* Enable HSI */
        SET_BIT(RCC_CR, RCC_CR_HSION_BIT); // HSION bit
        /* Wait until HSI is ready */
        while (GET_BIT(RCC_CR, RCC_CR_HSIRDY_BIT) == 0); // HSIRDY bit
        /* Select HSI as system clock */
        RCC_CFGR &= ~(0x03 << RCC_CFGR_SW_BITS);
        RCC_CFGR |= (RCC_HSI << RCC_CFGR_SW_BITS); // Select HSI as system clock source
        while (((RCC_CFGR >> 2) & 0x03) != RCC_HSI);
        Local_FunctionState = E_OK;

    /** @brief: Select PLL as system clock
     * If RCC_SYS_CLK is set to RCC_PLL, the function will configure and enable the PLL (Phase-Locked Loop) based on the specific parameters defined in RCC_config.h. The PLL can be configured to use either HSE or HSI as its input clock source, and it allows for a wide range of output frequencies by adjusting the multiplication and division factors. The function will ensure that the PLL is properly configured, enabled, and stable before selecting it as the system clock source. This option is typically used when a higher system clock frequency is required than what is provided by the HSE or HSI alone, making it suitable for performance-critical applications.
     * @note
     * - When RCC_SYS_CLK is set to RCC_PLL, the function will need to configure the PLL parameters (such as PLLM, PLLN, PLLP, and PLLQ) in
     * the RCC_PLLCFGR register based on the desired system clock frequency and the input clock source (HSE or HSI). After configuring the PLL, it will be enabled by setting the PLLON bit in the RCC_CR register. The function will then wait for the PLLRDY bit to be set, indicating that the PLL is stable and ready to be used as the system clock source. Finally, the PLL will be selected as the system clock source in the RCC_CFGR register. This configuration allows for a flexible and high-performance system clock setup, suitable for applications that require higher frequencies than what is provided by the HSE or HSI alone.
     */
      #elif RCC_SYS_CLK == RCC_PLL

        /* PLL configuration and enabling code should be implemented here based on the specific requirements of the application and the desired system clock frequency. This typically involves configuring the PLL source, multiplication and division factors, and then enabling the PLL and waiting for it to stabilize before selecting it as the system clock source. The exact implementation will depend on the specific PLL configuration parameters defined in RCC_config.h and the desired system clock frequency. */
            RCC_PLLCFGR &= ~((0x3F) << RCC_PLLCFGR_PLLM_BITS); // Clear PLLCFGR register before configuration
            RCC_PLLCFGR &= ~((0x1FF) << RCC_PLLCFGR_PLLN_BITS); // Clear PLLN bits
            RCC_PLLCFGR &= ~((0x03) << RCC_PLLCFGR_PLLP_BITS); // Clear PLLP bits
           
           #if RCC_PLLSRC == RCC_HSE

               RCC_EnableHSE();
               RCC_PLLCFGR |= (1 << RCC_PLLCFGR_PLLSRC_BIT); // Set PLL source to HSE

         #elif RCC_PLLSRC == RCC_HSI
                 SET_BIT(RCC_CR, RCC_CR_HSION_BIT); // HSION bit
                 /* Wait until HSI is ready */
                 while (GET_BIT(RCC_CR, RCC_CR_HSIRDY_BIT) == 0); // HSIRDY bit
                 RCC_PLLCFGR &= ~(1 << RCC_PLLCFGR_PLLSRC_BIT); // Set PLL source to HSI 
                
        #else

                #error "Invalid PLL source configuration in RCC_config.h"

        #endif

            RCC_PLLCFGR |= RCC_PLLP_ENCODE(RCC_PLLP);          
            RCC_PLLCFGR |= (RCC_PLLN << RCC_PLLCFGR_PLLN_BITS); // Configure PLLN multiplication factor
            RCC_PLLCFGR |= (RCC_PLLM << RCC_PLLCFGR_PLLM_BITS); // Configure PLLM division factor
            /* Configure PLL source, multiplication and division factors here based on RCC_config.h settings */
            SET_BIT(RCC_CR, RCC_CR_PLLON_BIT); // PLLON bit
            while (GET_BIT(RCC_CR, RCC_CR_PLLRDY_BIT) == 0); // PLLRDY bit
            FLASH_ACR |= (2 << 0);
            RCC_CFGR &= ~(0x03 << RCC_CFGR_SW_BITS); // Clear the SW bits
            RCC_CFGR |= (RCC_PLL << RCC_CFGR_SW_BITS); // Select PLL as system clock source
            while (((RCC_CFGR >> 2) & 0x03) != RCC_PLL);
            Local_FunctionState = E_OK;

    #else

        #error "Invalid system clock source configuration in RCC_config.h"

    #endif 
    
     
return Local_FunctionState;

}  

/**
 * @brief: Enable peripheral clock
 * 
 */
Std_ReturnType RCC_EnablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)

{
    Std_ReturnType Local_FunctionState = E_NOT_OK;


    switch (Copy_u8BusId)
    {

    case RCC_AHB1_BUS:

        SET_BIT(RCC_AHB1ENR, Copy_u8PeripheralId);
         Local_FunctionState = E_OK;
        break;

    case RCC_AHB2_BUS:

        SET_BIT(RCC_AHB2ENR, Copy_u8PeripheralId);
         Local_FunctionState = E_OK;
        break;
        
    case RCC_APB1_BUS:

        SET_BIT(RCC_APB1ENR, Copy_u8PeripheralId);
         Local_FunctionState = E_OK;
        break;

    case RCC_APB2_BUS:
    
        SET_BIT(RCC_APB2ENR, Copy_u8PeripheralId);
         Local_FunctionState = E_OK;
        break;

    default:
        Local_FunctionState = E_NOT_OK;
        break;
    }

    return Local_FunctionState;

}
          
/***
 * @brief: Disable peripheral clock
 * This function disables the clock for a specific peripheral connected to one of the buses (AHB1, AHB2, APB1, or APB2) in the STM32F401RCT6 microcontroller. It takes the bus ID and peripheral ID as parameters, identifies the correct register to modify based on the bus ID, and then clears the corresponding bit in the appropriate RCC enable
 */
Std_ReturnType RCC_DisablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
    Std_ReturnType Local_FunctionState = E_NOT_OK;


    switch (Copy_u8BusId)
    {

    case RCC_AHB1_BUS:

        CLR_BIT(RCC_AHB1ENR, Copy_u8PeripheralId);
         Local_FunctionState = E_OK;
        break;

    case RCC_AHB2_BUS:

        CLR_BIT(RCC_AHB2ENR, Copy_u8PeripheralId);
         Local_FunctionState = E_OK;
        break;
        
    case RCC_APB1_BUS:

        CLR_BIT(RCC_APB1ENR, Copy_u8PeripheralId);
         Local_FunctionState = E_OK;
        break;

    case RCC_APB2_BUS:
    
        CLR_BIT(RCC_APB2ENR, Copy_u8PeripheralId);
         Local_FunctionState = E_OK;
        break;

    default:
        Local_FunctionState = E_NOT_OK;
        break;
    }

    return Local_FunctionState;

}
