################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include STM32F7xx_HAL_Drivers_Sources/subdir.mk
-include Nucleo-F767ZI_Sources/subdir.mk
-include FreeRTOS_Sources/subdir.mk
-include Demo_Sources/subdir.mk
-include CycloneTCP_Sources/subdir.mk
-include Common_Sources/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ftp_client_demo
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ftp_client_demo.elf \

MAP_FILES += \
ftp_client_demo.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ftp_client_demo.list \

OBJCOPY_BIN += \
ftp_client_demo.bin \


# All Target
all: main-build

# Main-build Target
main-build: ftp_client_demo.elf secondary-outputs

# Tool invocations
ftp_client_demo.elf ftp_client_demo.map: $(OBJS) $(USER_OBJS) G:\WorkSpace\STM32\STM32_CYCLONETCP_EXAMPLES\CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2\demo\st\nucleo_f767zi\ftp_client_demo\stm32_cube_ide\stm32f767_flash.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "ftp_client_demo.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"G:\WorkSpace\STM32\STM32_CYCLONETCP_EXAMPLES\CycloneTCP_SSL_SSH_IPSEC_EAP_CRYPTO_Open_2_5_2\demo\st\nucleo_f767zi\ftp_client_demo\stm32_cube_ide\stm32f767_flash.ld" --specs=nosys.specs -Wl,-Map="ftp_client_demo.map" -Wl,--gc-sections -static  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ftp_client_demo.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ftp_client_demo.list"
	@echo 'Finished building: $@'
	@echo ' '

ftp_client_demo.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "ftp_client_demo.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout ftp_client_demo.bin ftp_client_demo.elf ftp_client_demo.list ftp_client_demo.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
