################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FW_Inicializaciones/FW_InitGPIOBaseBoard.c \
../src/FW_Inicializaciones/FW_InitKit_principal.c \
../src/FW_Inicializaciones/FW_InitOscilador.c \
../src/FW_Inicializaciones/cr_startup_lpc176x.c 

OBJS += \
./src/FW_Inicializaciones/FW_InitGPIOBaseBoard.o \
./src/FW_Inicializaciones/FW_InitKit_principal.o \
./src/FW_Inicializaciones/FW_InitOscilador.o \
./src/FW_Inicializaciones/cr_startup_lpc176x.o 

C_DEPS += \
./src/FW_Inicializaciones/FW_InitGPIOBaseBoard.d \
./src/FW_Inicializaciones/FW_InitKit_principal.d \
./src/FW_Inicializaciones/FW_InitOscilador.d \
./src/FW_Inicializaciones/cr_startup_lpc176x.d 


# Each subdirectory must supply rules for building sources it contributes
src/FW_Inicializaciones/%.o: ../src/FW_Inicializaciones/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\FW_Drivers" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\FW_Inicializaciones" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\inc" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\PRimitivas" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FW_Inicializaciones/cr_startup_lpc176x.o: ../src/FW_Inicializaciones/cr_startup_lpc176x.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\FW_Drivers" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\FW_Inicializaciones" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\inc" -I"C:\Users\Rama\Documents\LPCXpresso_8.2.2_650\TPOde0001\Teclado4x1\src\PRimitivas" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/FW_Inicializaciones/cr_startup_lpc176x.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


