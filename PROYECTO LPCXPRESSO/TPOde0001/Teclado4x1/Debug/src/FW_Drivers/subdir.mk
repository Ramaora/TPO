################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FW_Drivers/FW_7Seg.c \
../src/FW_Drivers/FW_GPIO.c \
../src/FW_Drivers/FW_Systick.c \
../src/FW_Drivers/KitInfo2FW_Teclado.c 

OBJS += \
./src/FW_Drivers/FW_7Seg.o \
./src/FW_Drivers/FW_GPIO.o \
./src/FW_Drivers/FW_Systick.o \
./src/FW_Drivers/KitInfo2FW_Teclado.o 

C_DEPS += \
./src/FW_Drivers/FW_7Seg.d \
./src/FW_Drivers/FW_GPIO.d \
./src/FW_Drivers/FW_Systick.d \
./src/FW_Drivers/KitInfo2FW_Teclado.d 


# Each subdirectory must supply rules for building sources it contributes
src/FW_Drivers/%.o: ../src/FW_Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\FW_Drivers" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\FW_Inicializaciones" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\inc" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\PRimitivas" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


