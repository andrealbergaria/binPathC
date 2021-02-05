################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../eclipse_asm/print_args.asm 

OBJS += \
./eclipse_asm/print_args.o 


# Each subdirectory must supply rules for building sources it contributes
eclipse_asm/%.o: ../eclipse_asm/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


