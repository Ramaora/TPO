################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Exp3.c \
../src/Exp4.c \
../src/InfotronicKit.c \
../src/dac.c \
../src/delay.c \
../src/interruption.c \
../src/lcd16.c \
../src/ports.c \
../src/ssp.c \
../src/systick.c \
../src/timer.c \
../src/uart0.c 

OBJS += \
./src/Exp3.o \
./src/Exp4.o \
./src/InfotronicKit.o \
./src/dac.o \
./src/delay.o \
./src/interruption.o \
./src/lcd16.o \
./src/ports.o \
./src/ssp.o \
./src/systick.o \
./src/timer.o \
./src/uart0.o 

C_DEPS += \
./src/Exp3.d \
./src/Exp4.d \
./src/InfotronicKit.d \
./src/dac.d \
./src/delay.d \
./src/interruption.d \
./src/lcd16.d \
./src/ports.d \
./src/ssp.d \
./src/systick.d \
./src/timer.d \
./src/uart0.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DUSE_MATRIX -D__REDLIB__ -DDEBUG -D__CODE_RED -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\MyLib\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


