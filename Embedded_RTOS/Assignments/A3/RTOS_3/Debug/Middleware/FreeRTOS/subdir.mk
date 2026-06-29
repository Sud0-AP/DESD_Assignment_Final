################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/croutine.c \
/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/event_groups.c \
/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/list.c \
/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/queue.c \
/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/stream_buffer.c \
/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/tasks.c \
/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/timers.c 

OBJS += \
./Middleware/FreeRTOS/croutine.o \
./Middleware/FreeRTOS/event_groups.o \
./Middleware/FreeRTOS/list.o \
./Middleware/FreeRTOS/queue.o \
./Middleware/FreeRTOS/stream_buffer.o \
./Middleware/FreeRTOS/tasks.o \
./Middleware/FreeRTOS/timers.o 

C_DEPS += \
./Middleware/FreeRTOS/croutine.d \
./Middleware/FreeRTOS/event_groups.d \
./Middleware/FreeRTOS/list.d \
./Middleware/FreeRTOS/queue.d \
./Middleware/FreeRTOS/stream_buffer.d \
./Middleware/FreeRTOS/tasks.d \
./Middleware/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Middleware/FreeRTOS/croutine.o: /home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/croutine.c Middleware/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/SEGGER -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/Config -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/FreeRTOSV11 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middleware/FreeRTOS/event_groups.o: /home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/event_groups.c Middleware/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/SEGGER -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/Config -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/FreeRTOSV11 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middleware/FreeRTOS/list.o: /home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/list.c Middleware/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/SEGGER -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/Config -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/FreeRTOSV11 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middleware/FreeRTOS/queue.o: /home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/queue.c Middleware/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/SEGGER -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/Config -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/FreeRTOSV11 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middleware/FreeRTOS/stream_buffer.o: /home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/stream_buffer.c Middleware/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/SEGGER -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/Config -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/FreeRTOSV11 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middleware/FreeRTOS/tasks.o: /home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/tasks.c Middleware/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/SEGGER -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/Config -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/FreeRTOSV11 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middleware/FreeRTOS/timers.o: /home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/timers.c Middleware/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/SEGGER -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/Config -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/FreeRTOSV11 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middleware-2f-FreeRTOS

clean-Middleware-2f-FreeRTOS:
	-$(RM) ./Middleware/FreeRTOS/croutine.cyclo ./Middleware/FreeRTOS/croutine.d ./Middleware/FreeRTOS/croutine.o ./Middleware/FreeRTOS/croutine.su ./Middleware/FreeRTOS/event_groups.cyclo ./Middleware/FreeRTOS/event_groups.d ./Middleware/FreeRTOS/event_groups.o ./Middleware/FreeRTOS/event_groups.su ./Middleware/FreeRTOS/list.cyclo ./Middleware/FreeRTOS/list.d ./Middleware/FreeRTOS/list.o ./Middleware/FreeRTOS/list.su ./Middleware/FreeRTOS/queue.cyclo ./Middleware/FreeRTOS/queue.d ./Middleware/FreeRTOS/queue.o ./Middleware/FreeRTOS/queue.su ./Middleware/FreeRTOS/stream_buffer.cyclo ./Middleware/FreeRTOS/stream_buffer.d ./Middleware/FreeRTOS/stream_buffer.o ./Middleware/FreeRTOS/stream_buffer.su ./Middleware/FreeRTOS/tasks.cyclo ./Middleware/FreeRTOS/tasks.d ./Middleware/FreeRTOS/tasks.o ./Middleware/FreeRTOS/tasks.su ./Middleware/FreeRTOS/timers.cyclo ./Middleware/FreeRTOS/timers.d ./Middleware/FreeRTOS/timers.o ./Middleware/FreeRTOS/timers.su

.PHONY: clean-Middleware-2f-FreeRTOS

