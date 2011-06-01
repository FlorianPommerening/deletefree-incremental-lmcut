################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/RelaxedOperator.cpp \
../src/RelaxedTask.cpp \
../src/Variable.cpp \
../src/hmax.cpp \
../src/hplusbnbmodule.cpp 

OBJS += \
./src/RelaxedOperator.o \
./src/RelaxedTask.o \
./src/Variable.o \
./src/hmax.o \
./src/hplusbnbmodule.o 

CPP_DEPS += \
./src/RelaxedOperator.d \
./src/RelaxedTask.d \
./src/Variable.d \
./src/hmax.d \
./src/hplusbnbmodule.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/python2.7 -I/usr/include -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


