################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.c \
/home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.c \
/home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.c 

S_UPPER_SRCS += \
/home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o \
./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o \
./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o 

S_UPPER_DEPS += \
./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d 

C_DEPS += \
./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.d \
./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.d \
./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o: /home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.c middleware/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/SEGGER -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/OS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o: /home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S middleware/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/SEGGER -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o: /home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.c middleware/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/SEGGER -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/OS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o: /home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.c middleware/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/SEGGER -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/OS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-middleware-2f-ThirdParty-2f-SEGGER-2f-SEGGER

clean-middleware-2f-ThirdParty-2f-SEGGER-2f-SEGGER:
	-$(RM) ./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.cyclo ./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.d ./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o ./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.su ./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d ./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o ./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.cyclo ./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.d ./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o ./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.su ./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.cyclo ./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.d ./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o ./middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.su

.PHONY: clean-middleware-2f-ThirdParty-2f-SEGGER-2f-SEGGER

