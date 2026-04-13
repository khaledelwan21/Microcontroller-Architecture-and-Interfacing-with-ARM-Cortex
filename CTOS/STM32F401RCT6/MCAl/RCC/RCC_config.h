/***************************************************
 * Author: khaled elwan
 * Date: 11/9/2023
 * Version: 1.0
 * Description: RCC_config.h
 ***************************************************/ 
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/**
 * @brief System clock source selection
 * Options:
 * - RCC_HSI: High-Speed Internal oscillator (16 MHz)
 * - RCC_HSE: High-Speed External oscillator (8 MHz)
 * - RCC_PLL: Phase-Locked Loop (configured with HSE as source)             
 * Default: RCC_HSE
 * Note: If RCC_PLL is selected, ensure that the PLL parameters (M, N, P, Q) are configured correctly in RCC_program.c
 * @note
 * - RCC_HSI: Internal RC oscillator, typically 16 MHz, used for low-power applications or when an external crystal is not available.
 * - RCC_HSE: External crystal oscillator, typically 8 MHz, used for higher precision       and stability, especially in applications requiring accurate timing.
 * - RCC_PLL: Phase-Locked Loop, used to generate higher frequencies from a lower frequency source (e.g., HSE). The PLL can be configured to achieve a wide range of system
 * frequencies, making it suitable for applications that require high performance.
 * - When using RCC_PLL, the PLL parameters (M, N, P, Q) must be configured in RCC_program.c to ensure the desired system clock frequency is achieved. The PLL configuration should be
 * done carefully to avoid exceeding the maximum allowed frequencies for the microcontroller and to ensure stable operation.
 * @code 
 * #define RCC_SYS_CLK RCC_HSE
 * 
 * @endcode
 */

#define RCC_SYS_CLK     RCC_HSE

/** @brief Clock source selection 
 * Options:
 * - RCC_RC_CLK: HSE bypass mode disabled (using external crystal)
 * - RCC_CRYSTAL_CLK: HSE bypass mode enabled (using external clock source)
 * Default: RCC_CRYSTAL_CLK
 * Note: This configuration is only relevant if RCC_SYS_CLK is set to RCC_HSE. If RCC_PLL is selected as the system clock source, the PLL will be configured to use HSE as its input, and the bypass mode will not affect the PLL operation.
 * @note
 * - RCC_RC_CLK: In this mode, the HSE is configured to use an external
 *    clock source (e.g., from another microcontroller or an oscillator module) instead of a crystal. This mode is typically used when the system is designed to receive a clock signal from an external source rather than generating it internally with a crystal.    
 * - RCC_CRYSTAL_CLK: In this mode, the HSE is configured to use an external crystal oscillator. This is the most common configuration for the HSE, providing a stable and accurate clock source for the system. The crystal frequency (e.g., 8 MHz) should match the expected frequency for the HSE to ensure proper operation.
 * @code
 * #define RCC_CLK_BYPASS RCC_CRYSTAL_CLK
*/

#if RCC_SYS_CLK == RCC_HSE


#define RCC_CLK_BYPASS    RCC_CRYSTAL_CLK   /**< HSE bypass mode disabled (using external crystal) */



#endif



#endif /* RCC_CONFIG_H */