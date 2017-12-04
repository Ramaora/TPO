################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Reproductor/src/FW_Drivers/FW_7Seg.c \
../Reproductor/src/FW_Drivers/FW_GPIO.c \
../Reproductor/src/FW_Drivers/FW_LCD.c \
../Reproductor/src/FW_Drivers/FW_Systick.c \
../Reproductor/src/FW_Drivers/FW_Timers.c \
../Reproductor/src/FW_Drivers/FW_UART0.c \
../Reproductor/src/FW_Drivers/KitInfo2FW_Teclado.c \
../Reproductor/src/FW_Drivers/cr_startup_lpc176x.c \
../Reproductor/src/FW_Drivers/ff.c \
../Reproductor/src/FW_Drivers/ffsystem.c \
../Reproductor/src/FW_Drivers/ffunicode.c \
../Reproductor/src/FW_Drivers/mmc_ssp.c \
../Reproductor/src/FW_Drivers/reproduccion.c \
../Reproductor/src/FW_Drivers/rtc176x.c \
../Reproductor/src/FW_Drivers/sound.c \
../Reproductor/src/FW_Drivers/startup176x.c \
../Reproductor/src/FW_Drivers/xprintf.c 

OBJS += \
./Reproductor/src/FW_Drivers/FW_7Seg.o \
./Reproductor/src/FW_Drivers/FW_GPIO.o \
./Reproductor/src/FW_Drivers/FW_LCD.o \
./Reproductor/src/FW_Drivers/FW_Systick.o \
./Reproductor/src/FW_Drivers/FW_Timers.o \
./Reproductor/src/FW_Drivers/FW_UART0.o \
./Reproductor/src/FW_Drivers/KitInfo2FW_Teclado.o \
./Reproductor/src/FW_Drivers/cr_startup_lpc176x.o \
./Reproductor/src/FW_Drivers/ff.o \
./Reproductor/src/FW_Drivers/ffsystem.o \
./Reproductor/src/FW_Drivers/ffunicode.o \
./Reproductor/src/FW_Drivers/mmc_ssp.o \
./Reproductor/src/FW_Drivers/reproduccion.o \
./Reproductor/src/FW_Drivers/rtc176x.o \
./Reproductor/src/FW_Drivers/sound.o \
./Reproductor/src/FW_Drivers/startup176x.o \
./Reproductor/src/FW_Drivers/xprintf.o 

C_DEPS += \
./Reproductor/src/FW_Drivers/FW_7Seg.d \
./Reproductor/src/FW_Drivers/FW_GPIO.d \
./Reproductor/src/FW_Drivers/FW_LCD.d \
./Reproductor/src/FW_Drivers/FW_Systick.d \
./Reproductor/src/FW_Drivers/FW_Timers.d \
./Reproductor/src/FW_Drivers/FW_UART0.d \
./Reproductor/src/FW_Drivers/KitInfo2FW_Teclado.d \
./Reproductor/src/FW_Drivers/cr_startup_lpc176x.d \
./Reproductor/src/FW_Drivers/ff.d \
./Reproductor/src/FW_Drivers/ffsystem.d \
./Reproductor/src/FW_Drivers/ffunicode.d \
./Reproductor/src/FW_Drivers/mmc_ssp.d \
./Reproductor/src/FW_Drivers/reproduccion.d \
./Reproductor/src/FW_Drivers/rtc176x.d \
./Reproductor/src/FW_Drivers/sound.d \
./Reproductor/src/FW_Drivers/startup176x.d \
./Reproductor/src/FW_Drivers/xprintf.d 


# Each subdirectory must supply rules for building sources it contributes
Reproductor/src/FW_Drivers/%.o: ../Reproductor/src/FW_Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


