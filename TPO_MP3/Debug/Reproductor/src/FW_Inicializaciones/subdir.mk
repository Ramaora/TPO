################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Reproductor/src/FW_Inicializaciones/FW_InitExpansion2.c \
../Reproductor/src/FW_Inicializaciones/FW_InitGPIOBaseBoard.c \
../Reproductor/src/FW_Inicializaciones/FW_InitKit_principal.c \
../Reproductor/src/FW_Inicializaciones/FW_InitOscilador.c \
../Reproductor/src/FW_Inicializaciones/FW_initUART0.c \
../Reproductor/src/FW_Inicializaciones/crp.c 

OBJS += \
./Reproductor/src/FW_Inicializaciones/FW_InitExpansion2.o \
./Reproductor/src/FW_Inicializaciones/FW_InitGPIOBaseBoard.o \
./Reproductor/src/FW_Inicializaciones/FW_InitKit_principal.o \
./Reproductor/src/FW_Inicializaciones/FW_InitOscilador.o \
./Reproductor/src/FW_Inicializaciones/FW_initUART0.o \
./Reproductor/src/FW_Inicializaciones/crp.o 

C_DEPS += \
./Reproductor/src/FW_Inicializaciones/FW_InitExpansion2.d \
./Reproductor/src/FW_Inicializaciones/FW_InitGPIOBaseBoard.d \
./Reproductor/src/FW_Inicializaciones/FW_InitKit_principal.d \
./Reproductor/src/FW_Inicializaciones/FW_InitOscilador.d \
./Reproductor/src/FW_Inicializaciones/FW_initUART0.d \
./Reproductor/src/FW_Inicializaciones/crp.d 


# Each subdirectory must supply rules for building sources it contributes
Reproductor/src/FW_Inicializaciones/%.o: ../Reproductor/src/FW_Inicializaciones/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


