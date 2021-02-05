################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../aes_brian/aes_amd64.asm \
../aes_brian/aes_x86_v1.asm \
../aes_brian/aes_x86_v2.asm 

C_SRCS += \
../aes_brian/aes_avs.c \
../aes_brian/aes_modes.c \
../aes_brian/aes_ni.c \
../aes_brian/aesaux.c \
../aes_brian/aescrypt.c \
../aes_brian/aesgav.c \
../aes_brian/aeskey.c \
../aes_brian/aeskey2.c \
../aes_brian/aesrav.c \
../aes_brian/aestab.c \
../aes_brian/aestmr.c \
../aes_brian/aestst.c \
../aes_brian/aesxam.c \
../aes_brian/andrec.c \
../aes_brian/modetest.c \
../aes_brian/rfc3686.c \
../aes_brian/tablegen.c 

OBJS += \
./aes_brian/aes_amd64.o \
./aes_brian/aes_avs.o \
./aes_brian/aes_modes.o \
./aes_brian/aes_ni.o \
./aes_brian/aes_x86_v1.o \
./aes_brian/aes_x86_v2.o \
./aes_brian/aesaux.o \
./aes_brian/aescrypt.o \
./aes_brian/aesgav.o \
./aes_brian/aeskey.o \
./aes_brian/aeskey2.o \
./aes_brian/aesrav.o \
./aes_brian/aestab.o \
./aes_brian/aestmr.o \
./aes_brian/aestst.o \
./aes_brian/aesxam.o \
./aes_brian/andrec.o \
./aes_brian/modetest.o \
./aes_brian/rfc3686.o \
./aes_brian/tablegen.o 

C_DEPS += \
./aes_brian/aes_avs.d \
./aes_brian/aes_modes.d \
./aes_brian/aes_ni.d \
./aes_brian/aesaux.d \
./aes_brian/aescrypt.d \
./aes_brian/aesgav.d \
./aes_brian/aeskey.d \
./aes_brian/aeskey2.d \
./aes_brian/aesrav.d \
./aes_brian/aestab.d \
./aes_brian/aestmr.d \
./aes_brian/aestst.d \
./aes_brian/aesxam.d \
./aes_brian/andrec.d \
./aes_brian/modetest.d \
./aes_brian/rfc3686.d \
./aes_brian/tablegen.d 


# Each subdirectory must supply rules for building sources it contributes
aes_brian/%.o: ../aes_brian/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

aes_brian/%.o: ../aes_brian/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


