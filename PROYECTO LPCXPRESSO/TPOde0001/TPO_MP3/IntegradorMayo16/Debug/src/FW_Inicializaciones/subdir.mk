################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FW_Inicializaciones/FW_InitExpansion2.c \
../src/FW_Inicializaciones/FW_InitGPIOBaseBoard.c \
../src/FW_Inicializaciones/FW_InitKit_principal.c \
../src/FW_Inicializaciones/FW_InitOscilador.c \
../src/FW_Inicializaciones/crp.c 

OBJS += \
./src/FW_Inicializaciones/FW_InitExpansion2.o \
./src/FW_Inicializaciones/FW_InitGPIOBaseBoard.o \
./src/FW_Inicializaciones/FW_InitKit_principal.o \
./src/FW_Inicializaciones/FW_InitOscilador.o \
./src/FW_Inicializaciones/crp.o 

C_DEPS += \
./src/FW_Inicializaciones/FW_InitExpansion2.d \
./src/FW_Inicializaciones/FW_InitGPIOBaseBoard.d \
./src/FW_Inicializaciones/FW_InitKit_principal.d \
./src/FW_Inicializaciones/FW_InitOscilador.d \
./src/FW_Inicializaciones/crp.d 


# Each subdirectory must supply rules for building sources it contributes
src/FW_Inicializaciones/%.o: ../src/FW_Inicializaciones/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\Usuario\Documents\LPCXpresso_8.2.2_650\workspace\IntegradorMayo16\src\FW_Drivers" -I"C:\Users\Usuario\Documents\LPCXpresso_8.2.2_650\workspace\IntegradorMayo16\src\FW_Inicializaciones" -I"C:\Users\Usuario\Documents\LPCXpresso_8.2.2_650\workspace\IntegradorMayo16\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


