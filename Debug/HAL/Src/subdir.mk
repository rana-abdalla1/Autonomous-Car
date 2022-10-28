################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Src/DCMotor_Prog.c \
../HAL/Src/LCD_Prog.c \
../HAL/Src/Servo_Prog.c \
../HAL/Src/Ultrasonic.c 

OBJS += \
./HAL/Src/DCMotor_Prog.o \
./HAL/Src/LCD_Prog.o \
./HAL/Src/Servo_Prog.o \
./HAL/Src/Ultrasonic.o 

C_DEPS += \
./HAL/Src/DCMotor_Prog.d \
./HAL/Src/LCD_Prog.d \
./HAL/Src/Servo_Prog.d \
./HAL/Src/Ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Src/%.o: ../HAL/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Rana.DESKTOP-NFHIRRT\Desktop\zeft\AutonomousCarProjectFinal\HAL\Inc" -I"C:\Users\Rana.DESKTOP-NFHIRRT\Desktop\zeft\AutonomousCarProjectFinal\MCAL\Inc" -I"C:\Users\Rana.DESKTOP-NFHIRRT\Desktop\zeft\AutonomousCarProjectFinal\LIB" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


