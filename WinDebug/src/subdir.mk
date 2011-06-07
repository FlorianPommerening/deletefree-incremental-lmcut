################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/RelaxedOperator.cpp \
../src/RelaxedTask.cpp \
../src/SASTask.cpp \
../src/Variable.cpp \
../src/hmax.cpp \
../src/hplusbnb.cpp 

OBJS += \
./src/RelaxedOperator.o \
./src/RelaxedTask.o \
./src/SASTask.o \
./src/Variable.o \
./src/hmax.o \
./src/hplusbnb.o 

CPP_DEPS += \
./src/RelaxedOperator.d \
./src/RelaxedTask.d \
./src/SASTask.d \
./src/Variable.d \
./src/hmax.d \
./src/hplusbnb.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Program Files\boost" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


