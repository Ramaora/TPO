################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include IntegradorMayo16/src/Primitivas/subdir.mk
-include IntegradorMayo16/src/FW_Inicializaciones/subdir.mk
-include IntegradorMayo16/src/FW_Drivers/subdir.mk
-include IntegradorMayo16/src/subdir.mk
-include IntegradorMayo16/Debug/src/FW_Inicializaciones/subdir.mk
-include IntegradorMayo16/Debug/src/FW_Drivers/subdir.mk
-include IntegradorMayo16/Debug/src/subdir.mk
-include .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: TPO_MP3.axf

# Tool invocations
TPO_MP3.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="TPO_MP3.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "TPO_MP3_Debug.ld" -o "TPO_MP3.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) TPO_MP3.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "TPO_MP3.axf"; # arm-none-eabi-objcopy -v -O binary "TPO_MP3.axf" "TPO_MP3.bin" ; # checksum -p LPC1769 -d "TPO_MP3.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
