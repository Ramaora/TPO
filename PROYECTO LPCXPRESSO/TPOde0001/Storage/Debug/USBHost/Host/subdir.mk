################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USBHost/Host/usbhost_lpc17xx.c 

OBJS += \
./USBHost/Host/usbhost_lpc17xx.o 

C_DEPS += \
./USBHost/Host/usbhost_lpc17xx.d 


# Each subdirectory must supply rules for building sources it contributes
USBHost/Host/%.o: ../USBHost/Host/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DNDEBUG -D__CODE_RED -D__USE_CMSIS=CMSISv2p00_LPC17xx -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Storage\Application" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Storage\FatFs" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Storage\FatFs\option" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Storage\SD" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Storage\USBHost" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Storage\USBHost\Host" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Storage\USBHost\Include" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Storage\USBHost\MassStorage" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


