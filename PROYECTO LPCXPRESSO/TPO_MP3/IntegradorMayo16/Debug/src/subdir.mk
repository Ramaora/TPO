################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Maq_Serie.c \
../src/main.c 

OBJS += \
./src/Maq_Serie.o \
./src/main.o 

C_DEPS += \
./src/Maq_Serie.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\Rama\Documents\GitHub\TPO\PROYECTO LPCXPRESSO\TPO_MP3\IntegradorMayo16\src\FW_Drivers" -I"C:\Users\Rama\Documents\GitHub\TPO\PROYECTO LPCXPRESSO\TPO_MP3\IntegradorMayo16\src\FW_Inicializaciones" -I"C:\Users\Rama\Documents\GitHub\TPO\PROYECTO LPCXPRESSO\TPO_MP3\IntegradorMayo16\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


