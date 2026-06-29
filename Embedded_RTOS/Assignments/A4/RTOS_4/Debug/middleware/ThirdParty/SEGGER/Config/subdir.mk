################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.c 

OBJS += \
./middleware/ThirdParty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.o 

C_DEPS += \
./middleware/ThirdParty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
middleware/ThirdParty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.o: /home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.c middleware/ThirdParty/SEGGER/Config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/SEGGER -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/OS -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config -I/home/desd/STM32CubeIDE/workspace_1.18.0/Middleware/SEGGER/FreeRTOSV11 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-middleware-2f-ThirdParty-2f-SEGGER-2f-Config

clean-middleware-2f-ThirdParty-2f-SEGGER-2f-Config:
	-$(RM) ./middleware/ThirdParty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.cyclo ./middleware/ThirdParty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.d ./middleware/ThirdParty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.o ./middleware/ThirdParty/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.su

.PHONY: clean-middleware-2f-ThirdParty-2f-SEGGER-2f-Config

