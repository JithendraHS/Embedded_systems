#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Make file to compile multiple files, link them together and create a final 
# output executable
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE_NAME>.i - Builds <FILE_NAME>.i object file
#      <FILE_NAME>.asm - Builds <FILE_NAME>.asm object file
#      <FILE_NAME>.o - Builds <FILE_NAME>.o object file
#      compile-all - compile all c files and creates object files
#      build - Builds and links all source files
#      clean - removes all generated files
#
# Platform Overrides:
#      PLATFORM = platform on which final executable file going to run
#      COURSE = Select course to run functions under course1.c file
#      VERBOSE = Flag used to enable print_array function to print array elements
#
#------------------------------------------------------------------------------
include sources.mk

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs

# Platform Overrides
PLATFORM = HOST
COURSE = NOT_COURSE1
VERBOSE = DISABLE

ifeq ($(PLATFORM),HOST)
  CC = gcc
  CFLAGS = -Wall -Werror -g -O0 -std=c99 $(INCLUDES) -o $@ $^ -DHOST
  OBJS =  main.o memory.o data.o course1.o stats.o
  DEPS =  main.d memory.d data.d course1.d stats.d
else
  CC = arm-none-eabi-gcc
  CFLAGS = -mcpu=$(CPU) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -march=$(ARCH) --specs=$(SPECS) -Wall -Werror -g -O0 -std=c99 $(INCLUDES) -o $@ $^ -DMSP432
  OBJS = main.d memory.o data.o course1.o stats.o interrupts_msp432p401r_gcc.o startup_msp432p401r_gcc.o system_msp432p401r.o
  DEPS = main.d memory.d data.d course1.d stats.d interrupts_msp432p401r_gcc.d startup_msp432p401r_gcc.d system_msp432p401r.d
endif

ifeq ($(COURSE), COURSE1)
  CFLAGS += -DCOURSE1
endif
ifeq ($(VERBOSE),ENABLE)
  CFLAGS += -DVERBOSE
endif

# Compiler Flags and Defines
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
TARGET = c1m2
CPPFLAGS = -E

%.i : src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS)
	@echo --created preprocessor file $@--

%.asm : src/%.c
	$(CC) -S $(CFLAGS)
	@echo --created assembly file $@--

%.o : src/%.c
	$(CC) -c $(CFLAGS)
	@echo --created object file $@--

%.d : src/%.c
	$(CC) -M $^ $(CFLAGS)
	@echo -- created dependency file $@--

.PHONY: compile-all
compile-all : $(OBJS)
	@echo --compiled all c files $(OBJS)--

.PHONY: build
build: $(DEPS) $(TARGET).out

$(TARGET).out: $(OBJS)
ifeq ($(PLATFORM),HOST)
	$(CC) $(CFLAGS)
else
	$(CC) $(LDFLAGS) $(CFLAGS)
endif
	@echo --created excecutable file $(TARGET).out--
	@echo !!! Size info about executable file !!!
	size --format=GNU $(TARGET).out


.PHONY: clean
clean:
	@echo "--cleaning--"
	rm -f *.o *.out *.map *.asm *.i *.d *.s
