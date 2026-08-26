/***************************************************
 * Author: khaled elwan
 * Date: 24/8/2026
 * Version: 1.0
 * Description: STK_config.h
 ***************************************************/
#ifndef STK_CONFIG_H
#define STK_CONFIG_H



/**
 * @brief STK_CLK_SOURCE
 * @note: This macro defines the clock source for the SysTick timer.
    * It can be set to either STK_AHB_DIV_8 or STK_AHB
 * @note: The available options are:
 * @param STK_AHB_DIV_8
 * @param STK_AHB
 **/


#define STK_CLK_SOURCE STK_AHB_DIV_8


/**
 * @brief STK_CTRL_INTERRUPT_ENABLE
 * @note: This macro defines whether the SysTick interrupt is enabled.
 * @note: The available options are:
 * @param STK_CTRL_INTERRUPT_ENABLE
 * @param STK_CTRL_INTERRUPT_DISABLE
 **/

#define STK_CTRL_INTERRUPT_ENABLE STK_CTRL_INTERRUPT_DISABLE






#endif