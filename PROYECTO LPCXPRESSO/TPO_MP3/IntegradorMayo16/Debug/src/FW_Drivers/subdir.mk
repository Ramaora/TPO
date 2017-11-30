################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FW_Drivers/FW_7Seg.c \
../src/FW_Drivers/FW_GPIO.c \
../src/FW_Drivers/FW_LCD.c \
../src/FW_Drivers/FW_Systick.c \
../src/FW_Drivers/FW_Timers.c \
../src/FW_Drivers/FW_UART0.c \
../src/FW_Drivers/KitInfo2FW_Teclado.c \
../src/FW_Drivers/cr_startup_lpc176x.c \
../src/FW_Drivers/ff.c \
../src/FW_Drivers/ffsystem.c \
../src/FW_Drivers/ffunicode.c \
../src/FW_Drivers/mmc_ssp.c \
../src/FW_Drivers/reproduccion.c \
../src/FW_Drivers/rtc176x.c \
../src/FW_Drivers/sound.c \
../src/FW_Drivers/startup176x.c \
../src/FW_Drivers/xprintf.c 

OBJS += \
./src/FW_Drivers/FW_7Seg.o \
./src/FW_Drivers/FW_GPIO.o \
./src/FW_Drivers/FW_LCD.o \
./src/FW_Drivers/FW_Systick.o \
./src/FW_Drivers/FW_Timers.o \
./src/FW_Drivers/FW_UART0.o \
./src/FW_Drivers/KitInfo2FW_Teclado.o \
./src/FW_Drivers/cr_startup_lpc176x.o \
./src/FW_Drivers/ff.o \
./src/FW_Drivers/ffsystem.o \
./src/FW_Drivers/ffunicode.o \
./src/FW_Drivers/mmc_ssp.o \
./src/FW_Drivers/reproduccion.o \
./src/FW_Drivers/rtc176x.o \
./src/FW_Drivers/sound.o \
./src/FW_Drivers/startup176x.o \
./src/FW_Drivers/xprintf.o 

C_DEPS += \
./src/FW_Drivers/FW_7Seg.d \
./src/FW_Drivers/FW_GPIO.d \
./src/FW_Drivers/FW_LCD.d \
./src/FW_Drivers/FW_Systick.d \
./src/FW_Drivers/FW_Timers.d \
./src/FW_Drivers/FW_UART0.d \
./src/FW_Drivers/KitInfo2FW_Teclado.d \
./src/FW_Drivers/cr_startup_lpc176x.d \
./src/FW_Drivers/ff.d \
./src/FW_Drivers/ffsystem.d \
./src/FW_Drivers/ffunicode.d \
./src/FW_Drivers/mmc_ssp.d \
./src/FW_Drivers/reproduccion.d \
./src/FW_Drivers/rtc176x.d \
./src/FW_Drivers/sound.d \
./src/FW_Drivers/startup176x.d \
./src/FW_Drivers/xprintf.d 


# Each subdirectory must supply rules for building sources it contributes
src/FW_Drivers/%.o: ../src/FW_Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\Rama\Documents\GitHub\TPO\PROYECTO LPCXPRESSO\TPO_MP3\IntegradorMayo16\src\FW_Drivers" -I"C:\Users\Rama\Documents\GitHub\TPO\PROYECTO LPCXPRESSO\TPO_MP3\IntegradorMayo16\src\FW_Inicializaciones" -I"C:\Users\Rama\Documents\GitHub\TPO\PROYECTO LPCXPRESSO\TPO_MP3\IntegradorMayo16\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


