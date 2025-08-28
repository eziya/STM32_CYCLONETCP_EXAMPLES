################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup_stm32f767xx.s 

C_SRCS += \
../syscalls.c 

OBJS += \
./startup_stm32f767xx.o \
./syscalls.o 

S_DEPS += \
./startup_stm32f767xx.d 

C_DEPS += \
./syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.s subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
%.o %.su %.cyclo: ../%.c subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32F767xx -DUSE_HAL_DRIVER -DUSE_STM32F7XX_NUCLEO_144 -D_WINSOCK_H -c -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../src" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../third_party/cmsis/core/include" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../third_party/st/devices/stm32f7xx" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../third_party/st/boards/stm32f7xx_nucleo_144" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../third_party/freertos/include" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../third_party/freertos/portable/gcc/arm_cm7/r0p1" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../common" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../cyclone_tcp" -Og -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean--2e-

clean--2e-:
	-$(RM) ./startup_stm32f767xx.d ./startup_stm32f767xx.o ./syscalls.cyclo ./syscalls.d ./syscalls.o ./syscalls.su

.PHONY: clean--2e-

