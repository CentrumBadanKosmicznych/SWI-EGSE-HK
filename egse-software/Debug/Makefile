################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../App/ \
../App/lib \
../App/src \
../App/src/Communication \
../Boards/ \
../Boards/SWI-PSU-BIAS-DM1 \
../Devices/ \
../HAL/ \
../HAL/AVR/ \
../HAL/AVR/MCU/ \
../HAL/AVR/MCU/ATMega128A/ \
../HAL/AVR/MCU/ATMega2560/ \
../HAL/AVR/MCU/ATMega328p/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../App/src/Communication/Buffer.cpp \
../App/src/Communication/CheckSum_Fletcher16.cpp \
../App/src/app.cpp \
../App/src/Communication/Frame.cpp \
../App/src/Communication/String.cpp \
../App/src/Dac.cpp \
../App/src/Hk.cpp \
../App/src/Switches.cpp \
../Boards/SWI-PSU-BIAS-DM1/board.cpp \
../Devices/ADC128S102.cpp \
../Devices/DAC121S101.cpp \
../Devices/MAX306EWIdouble.cpp \
../Devices/SN74HC138Ntriple.cpp \
../HAL/AVR/Timer.cpp \
../SWI-PSU-BIAS-DM1.cpp \
../HAL/AVR/GPIO.cpp \
../HAL/AVR/SPI.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
App/src/Communication/Buffer.o \
App/src/Communication/CheckSum_Fletcher16.o \
App/src/app.o \
App/src/Communication/Frame.o \
App/src/Communication/String.o \
App/src/Dac.o \
App/src/Hk.o \
App/src/Switches.o \
Boards/SWI-PSU-BIAS-DM1/board.o \
Devices/ADC128S102.o \
Devices/DAC121S101.o \
Devices/MAX306EWIdouble.o \
Devices/SN74HC138Ntriple.o \
HAL/AVR/Timer.o \
SWI-PSU-BIAS-DM1.o \
HAL/AVR/GPIO.o \
HAL/AVR/SPI.o

OBJS_AS_ARGS +=  \
App/src/Communication/Buffer.o \
App/src/Communication/CheckSum_Fletcher16.o \
App/src/app.o \
App/src/Communication/Frame.o \
App/src/Communication/String.o \
App/src/Dac.o \
App/src/Hk.o \
App/src/Switches.o \
Boards/SWI-PSU-BIAS-DM1/board.o \
Devices/ADC128S102.o \
Devices/DAC121S101.o \
Devices/MAX306EWIdouble.o \
Devices/SN74HC138Ntriple.o \
HAL/AVR/Timer.o \
SWI-PSU-BIAS-DM1.o \
HAL/AVR/GPIO.o \
HAL/AVR/SPI.o

C_DEPS +=  \
App/src/Communication/Buffer.d \
App/src/Communication/CheckSum_Fletcher16.d \
App/src/app.d \
App/src/Communication/Frame.d \
App/src/Communication/String.d \
App/src/Dac.d \
App/src/Hk.d \
App/src/Switches.d \
Boards/SWI-PSU-BIAS-DM1/board.d \
Devices/ADC128S102.d \
Devices/DAC121S101.d \
Devices/MAX306EWIdouble.d \
Devices/SN74HC138Ntriple.d \
HAL/AVR/Timer.d \
SWI-PSU-BIAS-DM1.d \
HAL/AVR/GPIO.d \
HAL/AVR/SPI.d

C_DEPS_AS_ARGS +=  \
App/src/Communication/Buffer.d \
App/src/Communication/CheckSum_Fletcher16.d \
App/src/app.d \
App/src/Communication/Frame.d \
App/src/Communication/String.d \
App/src/Dac.d \
App/src/Hk.d \
App/src/Switches.d \
Boards/SWI-PSU-BIAS-DM1/board.d \
Devices/ADC128S102.d \
Devices/DAC121S101.d \
Devices/MAX306EWIdouble.d \
Devices/SN74HC138Ntriple.d \
HAL/AVR/Timer.d \
SWI-PSU-BIAS-DM1.d \
HAL/AVR/GPIO.d \
HAL/AVR/SPI.d

OUTPUT_FILE_PATH +=SWI-PSU-HK-DM.elf

OUTPUT_FILE_PATH_AS_ARGS +=SWI-PSU-HK-DM.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler



































App/src/Communication/%.o: ../App/src/Communication/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.9.2
	$(QUOTE)D:\Programy_x86\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=8000000UL  -I"../HAL/AVR/MCU/ATMega2560" -I"../HAL/AVR" -I"D:\Programy_x86\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega1280 -B "D:\Programy_x86\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\gcc\dev\atmega1280" -c -std=c++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

App/src/%.o: ../App/src/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.9.2
	$(QUOTE)D:\Programy_x86\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=8000000UL  -I"../HAL/AVR/MCU/ATMega2560" -I"../HAL/AVR" -I"D:\Programy_x86\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega1280 -B "D:\Programy_x86\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\gcc\dev\atmega1280" -c -std=c++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Boards/SWI-PSU-BIAS-DM1/%.o: ../Boards/SWI-PSU-BIAS-DM1/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.9.2
	$(QUOTE)D:\Programy_x86\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=8000000UL  -I"../HAL/AVR/MCU/ATMega2560" -I"../HAL/AVR" -I"D:\Programy_x86\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega1280 -B "D:\Programy_x86\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\gcc\dev\atmega1280" -c -std=c++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Devices/%.o: ../Devices/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.9.2
	$(QUOTE)D:\Programy_x86\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=8000000UL  -I"../HAL/AVR/MCU/ATMega2560" -I"../HAL/AVR" -I"D:\Programy_x86\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega1280 -B "D:\Programy_x86\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\gcc\dev\atmega1280" -c -std=c++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

HAL/AVR/%.o: ../HAL/AVR/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.9.2
	$(QUOTE)D:\Programy_x86\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=8000000UL  -I"../HAL/AVR/MCU/ATMega2560" -I"../HAL/AVR" -I"D:\Programy_x86\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega1280 -B "D:\Programy_x86\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\gcc\dev\atmega1280" -c -std=c++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.9.2
	$(QUOTE)D:\Programy_x86\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=8000000UL  -I"../HAL/AVR/MCU/ATMega2560" -I"../HAL/AVR" -I"D:\Programy_x86\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega1280 -B "D:\Programy_x86\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\gcc\dev\atmega1280" -c -std=c++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 4.9.2
	$(QUOTE)D:\Programy_x86\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="SWI-PSU-HK-DM.map" -Wl,-u,vfprintf -Wl,--start-group -Wl,-lm -Wl,-lprintf_flt  -Wl,--end-group -Wl,-L"C:\Users\pkuligowski\Dropbox\juice_swi\psu\ucsoft\App\Communication"  -Wl,--gc-sections -mrelax -mmcu=atmega1280 -B "D:\Programy_x86\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\gcc\dev\atmega1280" -std=c++11  
	@echo Finished building target: $@
	"D:\Programy_x86\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "SWI-PSU-HK-DM.elf" "SWI-PSU-HK-DM.hex"
	"D:\Programy_x86\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "SWI-PSU-HK-DM.elf" "SWI-PSU-HK-DM.eep" || exit 0
	"D:\Programy_x86\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "SWI-PSU-HK-DM.elf" > "SWI-PSU-HK-DM.lss"
	"D:\Programy_x86\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "SWI-PSU-HK-DM.elf" "SWI-PSU-HK-DM.srec"
	"D:\Programy_x86\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "SWI-PSU-HK-DM.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "SWI-PSU-HK-DM.elf" "SWI-PSU-HK-DM.a" "SWI-PSU-HK-DM.hex" "SWI-PSU-HK-DM.lss" "SWI-PSU-HK-DM.eep" "SWI-PSU-HK-DM.map" "SWI-PSU-HK-DM.srec" "SWI-PSU-HK-DM.usersignatures"
	