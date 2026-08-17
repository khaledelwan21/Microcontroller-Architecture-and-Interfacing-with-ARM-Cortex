/***************************************************
 * Author: Khaled Elwan
 * Date: 17/8/2026
 * Version: 1.0
 * Description: NVIC_private.h
 ***************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


#define NVIC_BASE_ADDRESS    0xE000E100UL


/* NVIC Interrupt Set-Enable Registers */

#define NVIC_ISER0    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x000))
#define NVIC_ISER1    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x004))
#define NVIC_ISER2    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x008))


/* NVIC Interrupt Clear-Enable Registers */

#define NVIC_ICER0    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x080))
#define NVIC_ICER1    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x084))
#define NVIC_ICER2    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x088))


/* NVIC Interrupt Set-Pending Registers */

#define NVIC_ISPR0    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x100))
#define NVIC_ISPR1    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x104))
#define NVIC_ISPR2    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x108))


/* NVIC Interrupt Clear-Pending Registers */

#define NVIC_ICPR0    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x180))
#define NVIC_ICPR1    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x184))
#define NVIC_ICPR2    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x188))


/* NVIC Interrupt Active Bit Registers */

#define NVIC_IABR0    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x200))
#define NVIC_IABR1    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x204))
#define NVIC_IABR2    (*(volatile u32 *)(NVIC_BASE_ADDRESS + 0x208))

/* NVIC Interrupt Priority Registers */

#define NVIC_IPR_Base_Address    (*(volatile u8 *)(NVIC_BASE_ADDRESS + 0x300))

#define SCB_BASE_ADDRESS      0xE000ED00
#definne SCB_AIRCR    (*(volatile u32 *)(SCB_BASE_ADDRESS + 0x0C))


typedef u8 IRQn_Type;


#endif /* NVIC_PRIVATE_H */