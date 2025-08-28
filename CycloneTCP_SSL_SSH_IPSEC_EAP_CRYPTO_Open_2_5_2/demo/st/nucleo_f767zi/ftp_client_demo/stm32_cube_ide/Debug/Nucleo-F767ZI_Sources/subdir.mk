################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/third_party/st/boards/stm32f7xx_nucleo_144/stm32f7xx_nucleo_144.c 

OBJS += \
./Nucleo-F767ZI_Sources/stm32f7xx_nucleo_144.o 

C_DEPS += \
./Nucleo-F767ZI_Sources/stm32f7xx_nucleo_144.d 


# Each subdirectory must supply rules for building sources it contributes
Nucleo-F767ZI_Sources/stm32f7xx_nucleo_144.o: G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/third_party/st/boards/stm32f7xx_nucleo_144/stm32f7xx_nucleo_144.c Nucleo-F767ZI_Sources/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32F767xx -DUSE_HAL_DRIVER -DUSE_STM32F7XX_NUCLEO_144 -D_WINSOCK_H -c -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../src" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../third_party/cmsis/core/include" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../third_party/st/devices/stm32f7xx" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../third_party/st/drivers/stm32f7xx_hal_driver/inc" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../third_party/st/boards/stm32f7xx_nucleo_144" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../third_party/freertos/include" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../third_party/freertos/portable/gcc/arm_cm7/r0p1" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../common" -I"G:/WorkSpace/STM32/STM32_CYCLONETCP_EXAMPLES/CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2/demo/st/nucleo_f767zi/ftp_client_demo/stm32_cube_ide/../../../../../cyclone_tcp" -Og -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Nucleo-2d-F767ZI_Sources

clean-Nucleo-2d-F767ZI_Sources:
	-$(RM) ./Nucleo-F767ZI_Sources/stm32f7xx_nucleo_144.cyclo ./Nucleo-F767ZI_Sources/stm32f7xx_nucleo_144.d ./Nucleo-F767ZI_Sources/stm32f7xx_nucleo_144.o ./Nucleo-F767ZI_Sources/stm32f7xx_nucleo_144.su

.PHONY: clean-Nucleo-2d-F767ZI_Sources

