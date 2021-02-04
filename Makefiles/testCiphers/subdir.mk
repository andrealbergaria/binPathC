################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../testCiphers/aes256_lib.c \
../testCiphers/decrypt.c \
../testCiphers/encrypt.c \
../testCiphers/testCiphers.c \
../testCiphers/testKey.c \
../testCiphers/util.c 

O_SRCS += \
../testCiphers/aes256_lib.o \
../testCiphers/decrypt.o \
../testCiphers/encrypt.o \
../testCiphers/util.o 

OBJS += \
./testCiphers/aes256_lib.o \
./testCiphers/decrypt.o \
./testCiphers/encrypt.o \
./testCiphers/testCiphers.o \
./testCiphers/testKey.o \
./testCiphers/util.o 

C_DEPS += \
./testCiphers/aes256_lib.d \
./testCiphers/decrypt.d \
./testCiphers/encrypt.d \
./testCiphers/testCiphers.d \
./testCiphers/testKey.d \
./testCiphers/util.d 


# Each subdirectory must supply rules for building sources it contributes
testCiphers/%.o: ../testCiphers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


