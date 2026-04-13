    /***************************************************
 * Author: khaled elwan
 * Date: 10/4/2026
 * Version: 1.0
 * Description: RCC_private.h
 ***************************************************/  
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/** @brief Base address of the RCC peripheral
 * The RCC (Reset and Clock Control) peripheral is responsible for controlling the clock sources and distribution in the STM32F401RCT6 microcontroller. The base address is defined as a pointer to a volatile unsigned 32-bit integer, allowing direct access to the RCC registers.
 *  @note
 * - The base address of the RCC peripheral is 0x40023800, which is specific to the STM32F401RCT6 microcontroller. This address is used to access the RCC`
 * registers, such as RCC_CR, RCC_PLLCFGR, RCC_CFGR, RCC_AHB1ENR, RCC_AHB2ENR, RCC_APB1ENR, and RCC_APB2ENR. Each register has a specific offset from the base address, allowing for precise control over the clock configuration and management.
 * - The RCC_CR register is located at an offset of 0x00 from the base address and is used to control the clock sources and their readiness. The RCC_PLLCFGR register is
 * located at an offset of 0x04 and is used to configure the PLL (Phase-Locked Loop) parameters. The RCC_CFGR register, located at an offset of 0x08, is used to configure the clock source and prescalers. The RCC_AHB1ENR, RCC_AHB2ENR, RCC_APB1ENR, and RCC_APB2ENR registers are located at offsets of 0x30, 0x34, 0x40, and 0x44 respectively, and are used to enable or disable the clocks for various peripherals connected to the AHB1, AHB2, APB1, and APB2 buses.
 */


#define RCC_BASE_ADDRESS            (*(volatile u32*)0x40023800)
#define RCC_CR                      (*(volatile u32*)(RCC_BASE_ADDRESS + 0x00))
#define RCC_PLLCFGR                 (*(volatile u32*)(RCC_BASE_ADDRESS + 0x04))
#define RCC_CFGR                    (*(volatile u32*)(RCC_BASE_ADDRESS + 0x08))
#define RCC_AHB1ENR                 (*(volatile u32*)(RCC_BASE_ADDRESS + 0x30))
#define RCC_AHB2ENR                 (*(volatile u32*)(RCC_BASE_ADDRESS + 0x34))
#define RCC_APB1ENR                 (*(volatile u32*)(RCC_BASE_ADDRESS + 0x40))
#define RCC_APB2ENR                 (*(volatile u32*)(RCC_BASE_ADDRESS + 0x44))       



#define RCC_CR_HSON_BIT                     16
#define RCC_CR_HSERDY_BIT                   17
#define RCC_CR_HSEBYP_BIT                   18
#define RCC_CR_PLLON_BIT                    24
#define RCC_CR_PLLRDY_BIT                   25
#define RCC_CR_CSSON_BIT                    19
#define RCC_CR_CSSRDY_BIT                   20
#define RCC_CR_HSION_BIT                    0
#define RCC_CR_HSIRDY_BIT                   1
#define RCC_CR_HSITRIM_BITS                 3:0
#define RCC_CR_HSICAL_BITS                  7:4          
#define RCC_CR_PLLI2SON_BIT                 26
#define RCC_CR_PLLI2SRDY_BIT                27
#define RCC_CR_PLLSAION_BIT                 28
#define RCC_CR_PLLSAIRDY_BIT                29

#define RCC_PLLCFGR_PLLM_BITS              5:0
#define RCC_PLLCFGR_PLLN_BITS              14:6
#define RCC_PLLCFGR_PLLP_BITS              17:16            
#define RCC_PLLCFGR_PLLQ_BITS              27:24
#define RCC_PLLCFGR_PLLSRC_BIT             22
#define RCC_PLLCFGR_PLLREN_BIT             31
#define RCC_PLLCFGR_PLLR_BIT               28
#define RCC_PLLCFGR_PLLPDIV_BIT            25
#define RCC_PLLCFGR_PLLPEN_BIT             30
#define RCC_PLLCFGR_PLLQEN_BIT             29

#define RCC_CFGR_SW_BITS                   0
#define RCC_CFGR_SWS_BITS                  3:2
#define RCC_CFGR_HPRE_BITS                 7:4
#define RCC_CFGR_PPRE1_BITS               12:10
#define RCC_CFGR_PPRE2_BITS               15:13
#define RCC_CFGR_RTCPRE_BITS              23:16
#define RCC_CFGR_MCO1_BITS                21:22
#define RCC_CFGR_MCO1PRE_BITS             24:27
#define RCC_CFGR_MCO2_BITS                30:31
#define RCC_CFGR_MCO2PRE_BITS             27:30





#define RCC_HSI                              0x00 
#define RCC_HSE                              0x01
#define RCC_PLL                              0x02


#define RCC_RC_CLK                           0
#define RCC_CRYSTAL_CLK                      1







#endif /* RCC_PRIVATE_H */