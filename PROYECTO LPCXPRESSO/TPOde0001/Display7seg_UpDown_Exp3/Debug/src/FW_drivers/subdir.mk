################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FW_drivers/FW_7Seg_Exp3.c \
../src/FW_drivers/FW_GPIO.c \
../src/FW_drivers/FW_Systick.c 

OBJS += \
./src/FW_drivers/FW_7Seg_Exp3.o \
./src/FW_drivers/FW_GPIO.o \
./src/FW_drivers/FW_Systick.o 

C_DEPS += \
./src/FW_drivers/FW_7Seg_Exp3.d \
./src/FW_drivers/FW_GPIO.d \
./src/FW_drivers/FW_Systick.d 


# Each subdirectory must supply rules for building sources it contributes
src/FW_drivers/%.o: ../src/FW_drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -I"/home/marcelo/LPCXpresso/workspace2016/Display7seg_UpDown_Exp3/src/FW_drivers" -I"/home/marcelo/LPCXpresso/workspace2016/Display7seg_UpDown_Exp3/src/FW_inicializaciones" -I"/home/marcelo/LPCXpresso/workspace2016/Display7seg_UpDown_Exp3/src/Primitivas" -I"/home/marcelo/LPCXpresso/workspace2016/Display7seg_UpDown_Exp3/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


