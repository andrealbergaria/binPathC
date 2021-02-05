################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include wolfssl/subdir.mk
-include testc/subdir.mk
-include testCiphers/subdir.mk
-include original_wikipedia_c_implementation/subdir.mk
-include ideas/scratchpad/subdir.mk
-include ideas/add_equals_sub/subdir.mk
-include ideas/subdir.mk
-include eclipse_asm/subdir.mk
-include aes_brian/python_binding/subdir.mk
-include aes_brian/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: binPathC

# Tool invocations
binPathC: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc  -o "binPathC" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) binPathC
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
