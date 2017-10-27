################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FW_inicializaciones/FW_InitBaseBoard.c \
../src/FW_inicializaciones/FW_InitDisplay_Exp3.c \
../src/FW_inicializaciones/FW_InitKit_principal.c \
../src/FW_inicializaciones/FW_InitOscilador.c \
../src/FW_inicializaciones/cr_startup_lpc175x_6x.c \
../src/FW_inicializaciones/crp.c 

OBJS += \
./src/FW_inicializaciones/FW_InitBaseBoard.o \
./src/FW_inicializaciones/FW_InitDisplay_Exp3.o \
./src/FW_inicializaciones/FW_InitKit_principal.o \
./src/FW_inicializaciones/FW_InitOscilador.o \
./src/FW_inicializaciones/cr_startup_lpc175x_6x.o \
./src/FW_inicializaciones/crp.o 

C_DEPS += \
./src/FW_inicializaciones/FW_InitBaseBoard.d \
./src/FW_inicializaciones/FW_InitDisplay_Exp3.d \
./src/FW_inicializaciones/FW_InitKit_principal.d \
./src/FW_inicializaciones/FW_InitOscilador.d \
./src/FW_inicializaciones/cr_startup_lpc175x_6x.d \
./src/FW_inicializaciones/crp.d 


# Each subdirectory must supply rules for building sources it contributes
src/FW_inicializaciones/%.o: ../src/FW_inicializaciones/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -I"/home/marcelo/LPCXpresso/workspace2016/Display7seg_UpDown_Exp3/src/FW_drivers" -I"/home/marcelo/LPCXpresso/workspace2016/Display7seg_UpDown_Exp3/src/FW_inicializaciones" -I"/home/marcelo/LPCXpresso/workspace2016/Display7seg_UpDown_Exp3/src/Primitivas" -I"/home/marcelo/LPCXpresso/workspace2016/Display7seg_UpDown_Exp3/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


