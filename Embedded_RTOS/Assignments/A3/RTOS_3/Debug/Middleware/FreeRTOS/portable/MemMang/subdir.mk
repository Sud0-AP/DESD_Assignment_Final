################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/portable/MemMang/heap_4.c 

OBJS += \
./Middleware/FreeRTOS/portable/MemMang/heap_4.o 

C_DEPS += \
./Middleware/FreeRTOS/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Middleware/FreeRTOS/portable/MemMang/heap_4.o: /home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/portable/MemMang/heap_4.c Middleware/FreeRTOS/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/SEGGER -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/Config -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/FreeRTOSV11 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middleware-2f-FreeRTOS-2f-portable-2f-MemMang

clean-Middleware-2f-FreeRTOS-2f-portable-2f-MemMang:
	-$(RM) ./Middleware/FreeRTOS/portable/MemMang/heap_4.cyclo ./Middleware/FreeRTOS/portable/MemMang/heap_4.d ./Middleware/FreeRTOS/portable/MemMang/heap_4.o ./Middleware/FreeRTOS/portable/MemMang/heap_4.su

.PHONY: clean-Middleware-2f-FreeRTOS-2f-portable-2f-MemMang

