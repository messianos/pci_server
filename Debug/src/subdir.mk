################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Clarification.cpp \
../src/DatabaseInterface.cpp \
../src/Dateclass.cpp \
../src/Problem.cpp \
../src/Publication.cpp \
../src/Solution.cpp \
../src/User.cpp \
../src/pci_server.cpp \
../src/pci_template.cpp 

OBJS += \
./src/Clarification.o \
./src/DatabaseInterface.o \
./src/Dateclass.o \
./src/Problem.o \
./src/Publication.o \
./src/Solution.o \
./src/User.o \
./src/pci_server.o \
./src/pci_template.o 

CPP_DEPS += \
./src/Clarification.d \
./src/DatabaseInterface.d \
./src/Dateclass.d \
./src/Problem.d \
./src/Publication.d \
./src/Solution.d \
./src/User.d \
./src/pci_server.d \
./src/pci_template.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


