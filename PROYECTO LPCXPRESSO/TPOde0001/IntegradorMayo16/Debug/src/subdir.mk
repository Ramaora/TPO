################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/IntegradorMayo16.c \
../src/ff.c \
../src/ffsystem.c \
../src/ffunicode.c \
../src/mmc_ssp.c \
../src/rtc176x.c \
../src/sound.c \
../src/startup176x.c \
../src/uart176x.c \
../src/xprintf.c 

OBJS += \
./src/IntegradorMayo16.o \
./src/ff.o \
./src/ffsystem.o \
./src/ffunicode.o \
./src/mmc_ssp.o \
./src/rtc176x.o \
./src/sound.o \
./src/startup176x.o \
./src/uart176x.o \
./src/xprintf.o 

C_DEPS += \
./src/IntegradorMayo16.d \
./src/ff.d \
./src/ffsystem.d \
./src/ffunicode.d \
./src/mmc_ssp.d \
./src/rtc176x.d \
./src/sound.d \
./src/startup176x.d \
./src/uart176x.d \
./src/xprintf.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\IntegradorMayo16\src\FW_Drivers" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\IntegradorMayo16\src\FW_Inicializaciones" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\IntegradorMayo16\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


