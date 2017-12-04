################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IntegradorMayo16/src/FW_Drivers/FW_7Seg.c \
../IntegradorMayo16/src/FW_Drivers/FW_GPIO.c \
../IntegradorMayo16/src/FW_Drivers/FW_LCD.c \
../IntegradorMayo16/src/FW_Drivers/FW_Systick.c \
../IntegradorMayo16/src/FW_Drivers/FW_Timers.c \
../IntegradorMayo16/src/FW_Drivers/FW_UART0.c \
../IntegradorMayo16/src/FW_Drivers/KitInfo2FW_Teclado.c \
../IntegradorMayo16/src/FW_Drivers/cr_startup_lpc176x.c 

OBJS += \
./IntegradorMayo16/src/FW_Drivers/FW_7Seg.o \
./IntegradorMayo16/src/FW_Drivers/FW_GPIO.o \
./IntegradorMayo16/src/FW_Drivers/FW_LCD.o \
./IntegradorMayo16/src/FW_Drivers/FW_Systick.o \
./IntegradorMayo16/src/FW_Drivers/FW_Timers.o \
./IntegradorMayo16/src/FW_Drivers/FW_UART0.o \
./IntegradorMayo16/src/FW_Drivers/KitInfo2FW_Teclado.o \
./IntegradorMayo16/src/FW_Drivers/cr_startup_lpc176x.o 

C_DEPS += \
./IntegradorMayo16/src/FW_Drivers/FW_7Seg.d \
./IntegradorMayo16/src/FW_Drivers/FW_GPIO.d \
./IntegradorMayo16/src/FW_Drivers/FW_LCD.d \
./IntegradorMayo16/src/FW_Drivers/FW_Systick.d \
./IntegradorMayo16/src/FW_Drivers/FW_Timers.d \
./IntegradorMayo16/src/FW_Drivers/FW_UART0.d \
./IntegradorMayo16/src/FW_Drivers/KitInfo2FW_Teclado.d \
./IntegradorMayo16/src/FW_Drivers/cr_startup_lpc176x.d 


# Each subdirectory must supply rules for building sources it contributes
IntegradorMayo16/src/FW_Drivers/%.o: ../IntegradorMayo16/src/FW_Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"/home/matias/LPCXpresso/workspace2/TPO_MP3/IntegradorMayo16/inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


