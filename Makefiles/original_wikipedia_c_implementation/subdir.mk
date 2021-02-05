################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../original_wikipedia_c_implementation/aes256.c \
../original_wikipedia_c_implementation/demo.c 

O_SRCS += \
../original_wikipedia_c_implementation/aes256.o \
../original_wikipedia_c_implementation/demo.o 

OBJS += \
./original_wikipedia_c_implementation/aes256.o \
./original_wikipedia_c_implementation/demo.o 

C_DEPS += \
./original_wikipedia_c_implementation/aes256.d \
./original_wikipedia_c_implementation/demo.d 


# Each subdirectory must supply rules for building sources it contributes
original_wikipedia_c_implementation/%.o: ../original_wikipedia_c_implementation/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


