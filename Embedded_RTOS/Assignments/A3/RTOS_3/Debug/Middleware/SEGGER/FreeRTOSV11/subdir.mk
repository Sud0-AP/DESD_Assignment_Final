################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/FreeRTOSV11/SEGGER_SYSVIEW_FreeRTOS.c 

OBJS += \
./Middleware/SEGGER/FreeRTOSV11/SEGGER_SYSVIEW_FreeRTOS.o 

C_DEPS += \
./Middleware/SEGGER/FreeRTOSV11/SEGGER_SYSVIEW_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
Middleware/SEGGER/FreeRTOSV11/SEGGER_SYSVIEW_FreeRTOS.o: /home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/FreeRTOSV11/SEGGER_SYSVIEW_FreeRTOS.c Middleware/SEGGER/FreeRTOSV11/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/portable/GCC/ARM_CM4F -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS/include -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/FreeRTOS -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/SEGGER -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/Config -I/home/desd/DESD_Assignments/Embedded_RTOS/Project_Setup_Files/Middleware/SEGGER/FreeRTOSV11 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middleware-2f-SEGGER-2f-FreeRTOSV11

clean-Middleware-2f-SEGGER-2f-FreeRTOSV11:
	-$(RM) ./Middleware/SEGGER/FreeRTOSV11/SEGGER_SYSVIEW_FreeRTOS.cyclo ./Middleware/SEGGER/FreeRTOSV11/SEGGER_SYSVIEW_FreeRTOS.d ./Middleware/SEGGER/FreeRTOSV11/SEGGER_SYSVIEW_FreeRTOS.o ./Middleware/SEGGER/FreeRTOSV11/SEGGER_SYSVIEW_FreeRTOS.su

.PHONY: clean-Middleware-2f-SEGGER-2f-FreeRTOSV11

