################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/inc/FW_InitExpansion2.c 

OBJS += \
./src/inc/FW_InitExpansion2.o 

C_DEPS += \
./src/inc/FW_InitExpansion2.d 


# Each subdirectory must supply rules for building sources it contributes
src/inc/%.o: ../src/inc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\FW_Drivers" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\FW_Inicializaciones" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\inc" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\PRimitivas" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


