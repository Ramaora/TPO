################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Reproductor/src/Maq_Serie.c \
../Reproductor/src/main.c 

OBJS += \
./Reproductor/src/Maq_Serie.o \
./Reproductor/src/main.o 

C_DEPS += \
./Reproductor/src/Maq_Serie.d \
./Reproductor/src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Reproductor/src/%.o: ../Reproductor/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


