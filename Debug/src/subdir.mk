################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Gomoku.cpp \
../src/TADCasilla.cpp \
../src/TADJuego.cpp \
../src/TADTablero.cpp \
../src/entorno.cpp \
../src/pruebaCasilla.cpp \
../src/pruebaTablero.cpp 

CPP_DEPS += \
./src/Gomoku.d \
./src/TADCasilla.d \
./src/TADJuego.d \
./src/TADTablero.d \
./src/entorno.d \
./src/pruebaCasilla.d \
./src/pruebaTablero.d 

OBJS += \
./src/Gomoku.o \
./src/TADCasilla.o \
./src/TADJuego.o \
./src/TADTablero.o \
./src/entorno.o \
./src/pruebaCasilla.o \
./src/pruebaTablero.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Gomoku.d ./src/Gomoku.o ./src/TADCasilla.d ./src/TADCasilla.o ./src/TADJuego.d ./src/TADJuego.o ./src/TADTablero.d ./src/TADTablero.o ./src/entorno.d ./src/entorno.o ./src/pruebaCasilla.d ./src/pruebaCasilla.o ./src/pruebaTablero.d ./src/pruebaTablero.o

.PHONY: clean-src

