################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Aplicacion.c \
../src/main.c 

OBJS += \
./src/Aplicacion.o \
./src/main.o 

C_DEPS += \
./src/Aplicacion.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -I"/home/marcelo/LPCXpresso/workspace2016/Display7seg_UpDown_Exp3/src/FW_drivers" -I"/home/marcelo/LPCXpresso/workspace2016/Display7seg_UpDown_Exp3/src/FW_inicializaciones" -I"/home/marcelo/LPCXpresso/workspace2016/Display7seg_UpDown_Exp3/src/Primitivas" -I"/home/marcelo/LPCXpresso/workspace2016/Display7seg_UpDown_Exp3/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


