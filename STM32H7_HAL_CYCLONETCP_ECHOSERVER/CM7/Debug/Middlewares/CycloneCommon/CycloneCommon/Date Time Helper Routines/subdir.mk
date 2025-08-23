################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/STM32H7_HAL_CYCLONETCP_ECHOSERVER/Middlewares/Third_Party/Oryx-Embedded_CycloneCommon_CycloneCommon/common/date_time.c 

OBJS += \
./Middlewares/CycloneCommon/CycloneCommon/Date\ Time\ Helper\ Routines/date_time.o 

C_DEPS += \
./Middlewares/CycloneCommon/CycloneCommon/Date\ Time\ Helper\ Routines/date_time.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/CycloneCommon/CycloneCommon/Date\ Time\ Helper\ Routines/date_time.o: G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/STM32H7_HAL_CYCLONETCP_ECHOSERVER/Middlewares/Third_Party/Oryx-Embedded_CycloneCommon_CycloneCommon/common/date_time.c Middlewares/CycloneCommon/CycloneCommon/Date\ Time\ Helper\ Routines/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DECHO_SERVER_SUPPORT -DRTE_RTOS_FreeRTOS_CORE -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_PWR_DIRECT_SMPS_SUPPLY -c -I../Core/Inc -I../../Middlewares/Third_Party/Oryx-Embedded_CycloneTCP_CycloneTCP/cyclone_tcp/ -I../../Middlewares/Third_Party/Oryx-Embedded_CycloneTCP_CycloneTCP/cyclone_tcp/dhcp -I../../Middlewares/Third_Party/Oryx-Embedded_CycloneTCP_CycloneTCP/cyclone_tcp/core -I../../Middlewares/Third_Party/Oryx-Embedded_CycloneCommon_CycloneCommon/common/ -I../../Middlewares/Third_Party/Oryx-Embedded_CycloneCommon_CycloneCommon/common -I../../Middlewares/Third_Party/Oryx-Embedded_CycloneCommon_CycloneCommon/config -I../../Middlewares/Third_Party/Oryx-Embedded_CycloneTCP_CycloneTCP/cyclone_tcp/mdns -I../../Middlewares/Third_Party/Oryx-Embedded_CycloneTCP_CycloneTCP/cyclone_tcp/dns -I../../Middlewares/Third_Party/Oryx-Embedded_CycloneTCP_CycloneTCP/config -I../../Middlewares/Third_Party/Oryx-Embedded_CycloneTCP_CycloneTCP/cyclone_tcp/drivers/mac -I../../Middlewares/Third_Party/Oryx-Embedded_CycloneTCP_CycloneTCP/cyclone_tcp/echo -I../../Middlewares/Third_Party/Oryx-Embedded_CycloneTCP_CycloneTCP/cyclone_tcp/ipv4 -I../../Middlewares/Third_Party/Oryx-Embedded_CycloneTCP_CycloneTCP/cyclone_tcp/nat -I../../Middlewares/Third_Party/Oryx-Embedded_CycloneTCP_CycloneTCP/cyclone_tcp/drivers/phy -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/CycloneCommon/CycloneCommon/Date Time Helper Routines/date_time.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-CycloneCommon-2f-CycloneCommon-2f-Date-20-Time-20-Helper-20-Routines

clean-Middlewares-2f-CycloneCommon-2f-CycloneCommon-2f-Date-20-Time-20-Helper-20-Routines:
	-$(RM) ./Middlewares/CycloneCommon/CycloneCommon/Date\ Time\ Helper\ Routines/date_time.cyclo ./Middlewares/CycloneCommon/CycloneCommon/Date\ Time\ Helper\ Routines/date_time.d ./Middlewares/CycloneCommon/CycloneCommon/Date\ Time\ Helper\ Routines/date_time.o ./Middlewares/CycloneCommon/CycloneCommon/Date\ Time\ Helper\ Routines/date_time.su

.PHONY: clean-Middlewares-2f-CycloneCommon-2f-CycloneCommon-2f-Date-20-Time-20-Helper-20-Routines

