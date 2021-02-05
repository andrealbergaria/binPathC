################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../aes_brian/python_binding/aesmodule.c 

OBJS += \
./aes_brian/python_binding/aesmodule.o 

C_DEPS += \
./aes_brian/python_binding/aesmodule.d 


# Each subdirectory must supply rules for building sources it contributes
aes_brian/python_binding/%.o: ../aes_brian/python_binding/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


