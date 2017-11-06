################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IntegradorMayo16/src/FW_Inicializaciones/FW_InitExpansion2.c \
../IntegradorMayo16/src/FW_Inicializaciones/FW_InitGPIOBaseBoard.c \
../IntegradorMayo16/src/FW_Inicializaciones/FW_InitKit_principal.c \
../IntegradorMayo16/src/FW_Inicializaciones/FW_InitOscilador.c \
../IntegradorMayo16/src/FW_Inicializaciones/crp.c 

OBJS += \
./IntegradorMayo16/src/FW_Inicializaciones/FW_InitExpansion2.o \
./IntegradorMayo16/src/FW_Inicializaciones/FW_InitGPIOBaseBoard.o \
./IntegradorMayo16/src/FW_Inicializaciones/FW_InitKit_principal.o \
./IntegradorMayo16/src/FW_Inicializaciones/FW_InitOscilador.o \
./IntegradorMayo16/src/FW_Inicializaciones/crp.o 

C_DEPS += \
./IntegradorMayo16/src/FW_Inicializaciones/FW_InitExpansion2.d \
./IntegradorMayo16/src/FW_Inicializaciones/FW_InitGPIOBaseBoard.d \
./IntegradorMayo16/src/FW_Inicializaciones/FW_InitKit_principal.d \
./IntegradorMayo16/src/FW_Inicializaciones/FW_InitOscilador.d \
./IntegradorMayo16/src/FW_Inicializaciones/crp.d 


# Each subdirectory must supply rules for building sources it contributes
IntegradorMayo16/src/FW_Inicializaciones/%.o: ../IntegradorMayo16/src/FW_Inicializaciones/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"C:\Users\Liliana\Documents\LPCXpresso_8.2.2_650\workspace2\TPO_MP3\IntegradorMayo16\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


