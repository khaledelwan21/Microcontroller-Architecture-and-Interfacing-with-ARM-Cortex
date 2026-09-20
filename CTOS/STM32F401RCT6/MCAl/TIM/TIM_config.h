/************************************************** 
* Author: Khaled Ahmed Elwan
* Date: 19/9/2026
* Version: 1.0
* Description: TIM_config.h
***************************************************/
#ifndef TIM_CONFIG_H
#define TIM_CONFIG_H

#include "TIM_private.h"

/*******< TIM Clock >******************************/
#define TIM_CLK_HZ  84000000UL  

/*******< TIM PSC >****************************** */
#define TIM2_PSC   83
#define TIM3_PSC   83
#define TIM4_PSC   83
#define TIM5_PSC   83

/******< TIM ARR >****************************** */
#define TIM2_ARR   1000
#define TIM3_ARR   1000
#define TIM4_ARR   1000
#define TIM5_ARR   1000

/**
*@brief TIM Direction
*@param TIM_DIR options:
*        0: Up counter
*        1: Down counter
**/
#define TIM2_DIR   0
#define TIM3_DIR   0
#define TIM4_DIR   0
#define TIM5_DIR   0


/**
*@brief TIM Mode
*@param TIM_MODE options:
*        EDGE_ALIGNED
         CENTER_ALIGNED_MODE_1
         CENTER_ALIGNED_MODE_2
         CENTER_ALIGNED_MODE_3 
**/
#define TIM2_MODE  EDGE_ALIGNED
#define TIM3_MODE  EDGE_ALIGNED
#define TIM4_MODE  EDGE_ALIGNED
#define TIM5_MODE  EDGE_ALIGNED  

#define TIM2_BUFFER_MODE  DISABLE_BUFFER
#define TIM3_BUFFER_MODE  DISABLE_BUFFER
#define TIM4_BUFFER_MODE  DISABLE_BUFFER
#define TIM5_BUFFER_MODE  DISABLE_BUFFER





#endif