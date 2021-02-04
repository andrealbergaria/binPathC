################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ideas/add_equals_sub/have_a_binary_number_that_when_added_and_subtracted_adds_or_subtracts_conformalling.c \
../ideas/add_equals_sub/implement.c 

OBJS += \
./ideas/add_equals_sub/have_a_binary_number_that_when_added_and_subtracted_adds_or_subtracts_conformalling.o \
./ideas/add_equals_sub/implement.o 

C_DEPS += \
./ideas/add_equals_sub/have_a_binary_number_that_when_added_and_subtracted_adds_or_subtracts_conformalling.d \
./ideas/add_equals_sub/implement.d 


# Each subdirectory must supply rules for building sources it contributes
ideas/add_equals_sub/%.o: ../ideas/add_equals_sub/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


