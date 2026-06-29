################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/FreeRTOS/croutine.c \
/home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/FreeRTOS/event_groups.c \
/home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/FreeRTOS/list.c \
/home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/FreeRTOS/queue.c \
/home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/FreeRTOS/stream_buffer.c \
/home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/FreeRTOS/tasks.c \
/home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/FreeRTOS/timers.c 

OBJS += \
./middleware/ThirdParty/FreeRTOS/croutine.o \
./middleware/ThirdParty/FreeRTOS/event_groups.o \
./middleware/ThirdParty/FreeRTOS/list.o \
./middleware/ThirdParty/FreeRTOS/queue.o \
./middleware/ThirdParty/FreeRTOS/stream_buffer.o \
./middleware/ThirdParty/FreeRTOS/tasks.o \
./middleware/ThirdParty/FreeRTOS/timers.o 

C_DEPS += \
./middleware/ThirdParty/FreeRTOS/croutine.d \
./middleware/ThirdParty/FreeRTOS/event_groups.d \
./middleware/ThirdParty/FreeRTOS/list.d \
./middleware/ThirdParty/FreeRTOS/queue.d \
./middleware/ThirdParty/FreeRTOS/stream_buffer.d \
./middleware/ThirdParty/FreeRTOS/tasks.d \
./middleware/ThirdParty/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
middleware/ThirdParty/FreeRTOS/croutine.o: /home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/FreeRTOS/croutine.c middleware/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/SEGGER -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/OS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
middleware/ThirdParty/FreeRTOS/event_groups.o: /home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/FreeRTOS/event_groups.c middleware/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/SEGGER -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/OS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
middleware/ThirdParty/FreeRTOS/list.o: /home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/FreeRTOS/list.c middleware/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/SEGGER -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/OS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
middleware/ThirdParty/FreeRTOS/queue.o: /home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/FreeRTOS/queue.c middleware/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/SEGGER -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/OS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
middleware/ThirdParty/FreeRTOS/stream_buffer.o: /home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/FreeRTOS/stream_buffer.c middleware/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/SEGGER -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/OS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
middleware/ThirdParty/FreeRTOS/tasks.o: /home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/FreeRTOS/tasks.c middleware/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/SEGGER -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/OS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
middleware/ThirdParty/FreeRTOS/timers.o: /home/desd/DESD_Assignments/Embedded_RTOS/Data_Sharing_RTOS/Setup\ Files/middleware/ThirdParty/FreeRTOS/timers.c middleware/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/include -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/Config -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/SEGGER -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/FreeRTOS -I/home/desd/STM32CubeIDE/workspace_1.18.0/middleware/ThirdParty/SEGGER/OS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-middleware-2f-ThirdParty-2f-FreeRTOS

clean-middleware-2f-ThirdParty-2f-FreeRTOS:
	-$(RM) ./middleware/ThirdParty/FreeRTOS/croutine.cyclo ./middleware/ThirdParty/FreeRTOS/croutine.d ./middleware/ThirdParty/FreeRTOS/croutine.o ./middleware/ThirdParty/FreeRTOS/croutine.su ./middleware/ThirdParty/FreeRTOS/event_groups.cyclo ./middleware/ThirdParty/FreeRTOS/event_groups.d ./middleware/ThirdParty/FreeRTOS/event_groups.o ./middleware/ThirdParty/FreeRTOS/event_groups.su ./middleware/ThirdParty/FreeRTOS/list.cyclo ./middleware/ThirdParty/FreeRTOS/list.d ./middleware/ThirdParty/FreeRTOS/list.o ./middleware/ThirdParty/FreeRTOS/list.su ./middleware/ThirdParty/FreeRTOS/queue.cyclo ./middleware/ThirdParty/FreeRTOS/queue.d ./middleware/ThirdParty/FreeRTOS/queue.o ./middleware/ThirdParty/FreeRTOS/queue.su ./middleware/ThirdParty/FreeRTOS/stream_buffer.cyclo ./middleware/ThirdParty/FreeRTOS/stream_buffer.d ./middleware/ThirdParty/FreeRTOS/stream_buffer.o ./middleware/ThirdParty/FreeRTOS/stream_buffer.su ./middleware/ThirdParty/FreeRTOS/tasks.cyclo ./middleware/ThirdParty/FreeRTOS/tasks.d ./middleware/ThirdParty/FreeRTOS/tasks.o ./middleware/ThirdParty/FreeRTOS/tasks.su ./middleware/ThirdParty/FreeRTOS/timers.cyclo ./middleware/ThirdParty/FreeRTOS/timers.d ./middleware/ThirdParty/FreeRTOS/timers.o ./middleware/ThirdParty/FreeRTOS/timers.su

.PHONY: clean-middleware-2f-ThirdParty-2f-FreeRTOS

