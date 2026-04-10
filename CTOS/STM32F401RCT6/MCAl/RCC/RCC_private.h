    /***************************************************
 * Author: khaled elwan
 * Date: 10/4/2026
 * Version: 1.0
 * Description: RCC_private.h
 ***************************************************/  
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define RCC_BASE_ADDRESS (*(volatile u32*)0x40023800)
#define RCC_CR           (*(volatile u32*)(RCC_BASE_ADDRESS + 0x00))
#define RCC_PLLCFGR      (*(volatile u32*)(RCC_BASE_ADDRESS + 0x04))
#define RCC_CFGR         (*(volatile u32*)(RCC_BASE_ADDRESS + 0x08))
#define RCC_AHB1ENR      (*(volatile u32*)(RCC_BASE_ADDRESS + 0x30))
#define RCC_AHB2ENR      (*(volatile u32*)(RCC_BASE_ADDRESS + 0x34))
#define RCC_APB1ENR      (*(volatile u32*)(RCC_BASE_ADDRESS + 0x40))
#define RCC_APB2ENR      (*(volatile u32*)(RCC_BASE_ADDRESS + 0x44))       


 
#endif /* RCC_PRIVATE_H */