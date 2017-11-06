################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IntegradorMayo16/src/IntegradorMayo16.c \
../IntegradorMayo16/src/ff.c \
../IntegradorMayo16/src/ffsystem.c \
../IntegradorMayo16/src/ffunicode.c \
../IntegradorMayo16/src/mmc_ssp.c \
../IntegradorMayo16/src/rtc176x.c \
../IntegradorMayo16/src/sound.c \
../IntegradorMayo16/src/startup176x.c \
../IntegradorMayo16/src/uart176x.c \
../IntegradorMayo16/src/xprintf.c 

OBJS += \
./IntegradorMayo16/src/IntegradorMayo16.o \
./IntegradorMayo16/src/ff.o \
./IntegradorMayo16/src/ffsystem.o \
./IntegradorMayo16/src/ffunicode.o \
./IntegradorMayo16/src/mmc_ssp.o \
./IntegradorMayo16/src/rtc176x.o \
./IntegradorMayo16/src/sound.o \
./IntegradorMayo16/src/startup176x.o \
./IntegradorMayo16/src/uart176x.o \
./IntegradorMayo16/src/xprintf.o 

C_DEPS += \
./IntegradorMayo16/src/IntegradorMayo16.d \
./IntegradorMayo16/src/ff.d \
./IntegradorMayo16/src/ffsystem.d \
./IntegradorMayo16/src/ffunicode.d \
./IntegradorMayo16/src/mmc_ssp.d \
./IntegradorMayo16/src/rtc176x.d \
./IntegradorMayo16/src/sound.d \
./IntegradorMayo16/src/startup176x.d \
./IntegradorMayo16/src/uart176x.d \
./IntegradorMayo16/src/xprintf.d 


# Each subdirectory must supply rules for building sources it contributes
IntegradorMayo16/src/%.o: ../IntegradorMayo16/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"C:\Users\Liliana\Documents\LPCXpresso_8.2.2_650\workspace2\TPO_MP3\IntegradorMayo16\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


