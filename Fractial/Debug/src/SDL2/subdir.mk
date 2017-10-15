################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SDL2/Screen.cpp 

OBJS += \
./src/SDL2/Screen.o 

CPP_DEPS += \
./src/SDL2/Screen.d 


# Each subdirectory must supply rules for building sources it contributes
src/SDL2/%.o: ../src/SDL2/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DGXX_EXPERIMENTAL_CXX0X -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


