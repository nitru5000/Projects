################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Stop_Watch.lss \

FLASH_IMAGE += \
Stop_Watch.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Stop_Watch.elf secondary-outputs

# Tool invocations
Stop_Watch.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Stop_Watch.map -mmcu=atmega16 -o "Stop_Watch.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Stop_Watch.lss: Stop_Watch.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Stop_Watch.elf  >"Stop_Watch.lss"
	@echo 'Finished building: $@'
	@echo ' '

Stop_Watch.hex: Stop_Watch.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Stop_Watch.elf  "Stop_Watch.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Stop_Watch.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Stop_Watch.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Stop_Watch.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
