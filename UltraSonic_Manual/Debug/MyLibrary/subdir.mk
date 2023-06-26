################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MyLibrary/Hcsr.c 

OBJS += \
./MyLibrary/Hcsr.o 

C_DEPS += \
./MyLibrary/Hcsr.d 


# Each subdirectory must supply rules for building sources it contributes
MyLibrary/%.o MyLibrary/%.su: ../MyLibrary/%.c MyLibrary/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/KCT/KRSRI 2022/STM32/Hexapod/UltraSonic_Manual/MyLibrary" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MyLibrary

clean-MyLibrary:
	-$(RM) ./MyLibrary/Hcsr.d ./MyLibrary/Hcsr.o ./MyLibrary/Hcsr.su

.PHONY: clean-MyLibrary

