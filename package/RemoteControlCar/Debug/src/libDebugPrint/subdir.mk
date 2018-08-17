################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/libDebugPrint/dbgPrint.c 

OBJS += \
./src/libDebugPrint/dbgPrint.o 

C_DEPS += \
./src/libDebugPrint/dbgPrint.d 


# Each subdirectory must supply rules for building sources it contributes
src/libDebugPrint/%.o: ../src/libDebugPrint/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	mipsel-openwrt-linux-uclibc-gcc -I/home/yogi/myfile/openwrt-3.10.14/package/RemoteControlCar/src/libDebugPrint -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


