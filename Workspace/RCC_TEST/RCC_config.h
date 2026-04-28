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

 /**
  * @brief PLL configuration parameters
  * These parameters are used to configure the PLL when RCC_SYS_CLK is set to RCC_PLL. The values should be chosen based on the desired system clock frequency and the input clock source (HSE or HSI). The PLL configuration involves setting the division and multiplication factors to achieve the target frequency while ensuring that the PLL input and output frequencies are within the specified limits for the microcontroller.
  * @note
  * - RCC_PLLM: Division factor for the PLL input clock. This value divides the input clock frequency (HSE or HSI) to produce the PLL input frequency. The value should be chosen to ensure that the PLL input frequency is within the specified range (typically 1 to 2 MHz).
  * - RCC_PLLN: Multiplication factor for the PLL. This value               
  * multiplies the PLL input frequency to produce the VCO (Voltage-Controlled Oscillator) frequency. The value should be chosen to achieve the desired VCO frequency, which is typically in the range of 100 to 432 MHz.
  * - RCC_PLLP: Division factor for the main system clock. This value divides the
  * VCO frequency to produce the system clock frequency. The value can typically be 2, 4, 6, or 8, allowing for a wide range of system clock frequencies based on the VCO frequency.
  * @code
  * #define RCC_PLLM    2 ≤PLLM ≤63
  * #define RCC_PLLN    192 ≤PLLN ≤432
  * #define RCC_PLLP    2, 4, 6, or 8 
  */
 
#define RCC_PLLM      8   /**< PLLM division factor */
#define RCC_PLLN      336 /**< PLLN multiplication factor */
#define RCC_PLLP      2   /**< PLLP division factor */

/** @brief Encode PLLP value for register configuration
 * The RCC_PLLP_ENCODE macro takes a PLLP division factor (2, 4, 6, or 8) and encodes it into the format required for the RCC_PLLCFGR register. The PLLP division factor is encoded as follows:
 * - PLLP = 2: Encoded value = 0 (00 in binary)
 * - PLLP = 4: Encoded value = 1 (01 in binary)
 * - PLLP = 6: Encoded value = 2 (10 in binary)
 * - PLLP = 8: Encoded value = 3 (11 in binary)
 * The macro calculates the encoded value by dividing the PLLP division factor by 2 and subtracting 1, then shifting it to the correct position in the RCC_PLLCFGR register.
 * @code
 * #define RCC_PLLP_ENCODE(x)   (((x)/2 - 1) << RCC_PLLCFGR_PLLP_BITS)
 */ 

#define RCC_PLLP_ENCODE(x)   (((x)/2 - 1) << RCC_PLLCFGR_PLLP_BITS)

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
 * #define RCC_CLK_BYPASS RCC_CRYSTAL_CLK OR RCC_RC_CLK
*/


#define RCC_CLK_BYPASS    RCC_CRYSTAL_CLK   /**< HSE bypass mode disabled (using external crystal) */







#endif /* RCC_CONFIG_H */