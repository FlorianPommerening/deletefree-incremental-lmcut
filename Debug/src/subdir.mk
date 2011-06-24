################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BranchAndBoundSearch.cpp \
../src/Landmark.cpp \
../src/OperatorSelector.cpp \
../src/RelaxedTask.cpp \
../src/SASTask.cpp \
../src/SearchNode.cpp \
../src/UIntEx.cpp \
../src/Variable.cpp \
../src/hmax.cpp \
../src/hplusbnb.cpp \
../src/lmcut.cpp 

OBJS += \
./src/BranchAndBoundSearch.o \
./src/Landmark.o \
./src/OperatorSelector.o \
./src/RelaxedTask.o \
./src/SASTask.o \
./src/SearchNode.o \
./src/UIntEx.o \
./src/Variable.o \
./src/hmax.o \
./src/hplusbnb.o \
./src/lmcut.o 

CPP_DEPS += \
./src/BranchAndBoundSearch.d \
./src/Landmark.d \
./src/OperatorSelector.d \
./src/RelaxedTask.d \
./src/SASTask.d \
./src/SearchNode.d \
./src/UIntEx.d \
./src/Variable.d \
./src/hmax.d \
./src/hplusbnb.d \
./src/lmcut.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


