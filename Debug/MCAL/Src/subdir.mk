################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Src/DIO_Prog.c \
../MCAL/Src/Timer_Prog.c 

OBJS += \
./MCAL/Src/DIO_Prog.o \
./MCAL/Src/Timer_Prog.o 

C_DEPS += \
./MCAL/Src/DIO_Prog.d \
./MCAL/Src/Timer_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Src/%.o: ../MCAL/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Rana.DESKTOP-NFHIRRT\Desktop\zeft\AutonomousCarProjectFinal\HAL\Inc" -I"C:\Users\Rana.DESKTOP-NFHIRRT\Desktop\zeft\AutonomousCarProjectFinal\MCAL\Inc" -I"C:\Users\Rana.DESKTOP-NFHIRRT\Desktop\zeft\AutonomousCarProjectFinal\LIB" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


