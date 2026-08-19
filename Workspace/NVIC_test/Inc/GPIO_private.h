/***************************************************
 * Author: khaled elwan
 * Date: 30/4/2026
 * Version: 1.0
 * Description: GPIO_private.h
 ***************************************************/ 
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_



#define GPIOA_BASE_ADDRESS 0x40020000U  
#define GPIOB_BASE_ADDRESS 0x40020400U
#define GPIOC_BASE_ADDRESS 0x40020800U
#define GPIOD_BASE_ADDRESS 0x40020C00U
#define GPIOE_BASE_ADDRESS 0x40021000U
#define GPIOH_BASE_ADDRESS 0x40021C00U   // not used

/***************************< REGISTERS ADDRESSES FOR PORT A>****************************/

#define GPIOA_MODER   *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_OTYPER  *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_OSPEEDR *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_PUPDR   *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x0C))
#define GPIOA_IDR     *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x10)) 
#define GPIOA_ODR     *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_BSRR    *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x18))
#define GPIOA_LCKR    *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x1C))
#define GPIOA_AFRL    *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x20))
#define GPIOA_AFRH    *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x24)) 

/***************************< REGISTERS ADDRESSES FOR PORT B>****************************/

#define GPIOB_MODER   *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_OTYPER  *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x04)) 
#define GPIOB_OSPEEDR *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_PUPDR   *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x0C))
#define GPIOB_IDR     *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_ODR     *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_BSRR    *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x18))
#define GPIOB_LCKR    *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x1C))
#define GPIOB_AFRL    *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x20))
#define GPIOB_AFRH    *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x24))


/***************************< REGISTERS ADDRESSES FOR PORT C>****************************/

#define GPIOC_MODER   *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_OTYPER  *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x04)) 
#define GPIOC_OSPEEDR *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_PUPDR   *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x0C))
#define GPIOC_IDR     *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_ODR     *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_BSRR    *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x18))
#define GPIOC_LCKR    *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x1C))
#define GPIOC_AFRL    *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x20))
#define GPIOC_AFRH    *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x24))

/***************************< REGISTERS ADDRESSES FOR PORT D>****************************/

#define GPIOD_MODER   *((volatile u32*)(GPIOD_BASE_ADDRESS + 0x00))
#define GPIOD_OTYPER  *((volatile u32*)(GPIOD_BASE_ADDRESS + 0x04))
#define GPIOD_OSPEEDR *((volatile u32*)(GPIOD_BASE_ADDRESS + 0x08))
#define GPIOD_PUPDR   *((volatile u32*)(GPIOD_BASE_ADDRESS + 0x0C))
#define GPIOD_IDR     *((volatile u32*)(GPIOD_BASE_ADDRESS + 0x10))
#define GPIOD_ODR     *((volatile u32*)(GPIOD_BASE_ADDRESS + 0x14))
#define GPIOD_BSRR    *((volatile u32*)(GPIOD_BASE_ADDRESS + 0x18))
#define GPIOD_LCKR    *((volatile u32*)(GPIOD_BASE_ADDRESS + 0x1C))
#define GPIOD_AFRL    *((volatile u32*)(GPIOD_BASE_ADDRESS + 0x20))
#define GPIOD_AFRH    *((volatile u32*)(GPIOD_BASE_ADDRESS + 0x24))

/***************************< REGISTERS ADDRESSES FOR PORT E>****************************/
#define GPIOE_MODER   *((volatile u32*)(GPIOE_BASE_ADDRESS + 0x00))
#define GPIOE_OTYPER  *((volatile u32*)(GPIOE_BASE_ADDRESS + 0x04))
#define GPIOE_OSPEEDR *((volatile u32*)(GPIOE_BASE_ADDRESS + 0x08))
#define GPIOE_PUPDR   *((volatile u32*)(GPIOE_BASE_ADDRESS + 0x0C))
#define GPIOE_IDR     *((volatile u32*)(GPIOE_BASE_ADDRESS + 0x10))
#define GPIOE_ODR     *((volatile u32*)(GPIOE_BASE_ADDRESS + 0x14))
#define GPIOE_BSRR    *((volatile u32*)(GPIOE_BASE_ADDRESS + 0x18))
#define GPIOE_LCKR    *((volatile u32*)(GPIOE_BASE_ADDRESS + 0x1C))
#define GPIOE_AFRL    *((volatile u32*)(GPIOE_BASE_ADDRESS + 0x20))
#define GPIOE_AFRH    *((volatile u32*)(GPIOE_BASE_ADDRESS + 0x24))

/***************************< PORTS >************************************************/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4

/***************************< PINS BITS >********************************************/
#define GPIO_PIN_0  0
#define GPIO_PIN_1  1
#define GPIO_PIN_2  2
#define GPIO_PIN_3  3
#define GPIO_PIN_4  4
#define GPIO_PIN_5  5
#define GPIO_PIN_6  6   
#define GPIO_PIN_7  7
#define GPIO_PIN_8  8
#define GPIO_PIN_9  9
#define GPIO_PIN_10 10
#define GPIO_PIN_11 11
#define GPIO_PIN_12 12
#define GPIO_PIN_13 13
#define GPIO_PIN_14 14
#define GPIO_PIN_15 15

/*************************< MODES >************************************************/
#define GPIO_MODE_INPUT  0x00
#define GPIO_MODE_OUTPUT 0x01
#define GPIO_MODE_AF     0x02
#define GPIO_MODE_ANALOG 0x03

/*************************< OUTPUT TYPES >***********************************************/
#define GPIO_OUTPUT_TYPE_PUSH_PULL 0x00
#define GPIO_OUTPUT_TYPE_OPEN_DRAIN 0x01

/*************************< OUTPUT SPEEDS >***********************************************/
#define GPIO_OUTPUT_SPEED_LOW 0x00
#define GPIO_OUTPUT_SPEED_MEDIUM 0x01
#define GPIO_OUTPUT_SPEED_HIGH 0x02
#define GPIO_OUTPUT_SPEED_VERY_HIGH 0x03

/*************************< PULL UP DOWN RESISTORS >***********************************************/
#define GPIO_PULL_UP_DOWN_NONE 0x00
#define GPIO_PULL_UP_DOWN_PULL_UP 0x01
#define GPIO_PULL_UP_DOWN_PULL_DOWN 0x02    


/***********************< PIN VALUES >************************************/
#define GPIO_PIN_VALUE_LOW  0
#define GPIO_PIN_VALUE_HIGH 1





#endif