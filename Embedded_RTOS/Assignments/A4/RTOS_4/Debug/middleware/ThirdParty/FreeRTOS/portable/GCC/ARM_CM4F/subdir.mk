################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/port.o: /home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/port.c middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/SEGGER -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/OS -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config -I/home/desd/STM32CubeIDE/workspace_1.18.0/Middleware/SEGGER/FreeRTOSV11 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-middleware-2f-ThirdParty-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM4F

clean-middleware-2f-ThirdParty-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM4F:
	-$(RM) ./middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/port.cyclo ./middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/port.d ./middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/port.o ./middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/port.su

.PHONY: clean-middleware-2f-ThirdParty-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM4F

