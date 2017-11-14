################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IntegradorMayo16/src/Primitivas/PR_7Seg.c \
../IntegradorMayo16/src/Primitivas/PR_UART0.c 

OBJS += \
./IntegradorMayo16/src/Primitivas/PR_7Seg.o \
./IntegradorMayo16/src/Primitivas/PR_UART0.o 

C_DEPS += \
./IntegradorMayo16/src/Primitivas/PR_7Seg.d \
./IntegradorMayo16/src/Primitivas/PR_UART0.d 


# Each subdirectory must supply rules for building sources it contributes
IntegradorMayo16/src/Primitivas/%.o: ../IntegradorMayo16/src/Primitivas/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"/home/matias/LPCXpresso/workspace2/TPO_MP3/IntegradorMayo16/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


