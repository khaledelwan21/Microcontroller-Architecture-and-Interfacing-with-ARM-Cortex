################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/MCAl/RCC/RCC_program.c 

OBJS += \
./Core/MCAl/RCC/RCC_program.o 

C_DEPS += \
./Core/MCAl/RCC/RCC_program.d 


# Each subdirectory must supply rules for building sources it contributes
Core/MCAl/RCC/RCC_program.o: ../Core/MCAl/RCC/RCC_program.c Core/MCAl/RCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"C:/Users/khale/Microcontroller-Architecture-and-Interfacing-with-ARM-Cortex/Workspace/RCC/RCC/LIB" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-MCAl-2f-RCC

clean-Core-2f-MCAl-2f-RCC:
	-$(RM) ./Core/MCAl/RCC/RCC_program.cyclo ./Core/MCAl/RCC/RCC_program.d ./Core/MCAl/RCC/RCC_program.o ./Core/MCAl/RCC/RCC_program.su

.PHONY: clean-Core-2f-MCAl-2f-RCC

