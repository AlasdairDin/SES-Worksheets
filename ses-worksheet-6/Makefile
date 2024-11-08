# name of executable - change this to change the executables name

ELF=demo.elf

# object files

OBJS=  $(STARTUP)   stm32f10x_rcc.o stm32f10x_usart.o stm32f10x_gpio.o main.o strlen.o

# Tool path

TOOLROOT=/usr/bin

# Library paths

NEWLIB=../../newlib-arm-none-eabi/arm-none-eabi/newlib
NEWLIBINCLUDE=../../newlib-cygwin/newlib/libc/include/
LIBROOT=../STM32F10x_StdPeriph_Lib_V3.5.0

# Tools

CC=$(TOOLROOT)/arm-none-eabi-gcc
LD=$(TOOLROOT)/arm-none-eabi-gcc
AR=$(TOOLROOT)/arm-none-eabi-ar
AS=$(TOOLROOT)/arm-none-eabi-as

# Code Paths

DEVICE=$(LIBROOT)/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x
CORE=$(LIBROOT)/Libraries/CMSIS/CM3/CoreSupport
PERIPH=$(LIBROOT)/Libraries/STM32F10x_StdPeriph_Driver

# Search path for standard files

vpath %.c .

# Search path for perpheral library

vpath %.c $(CORE)
vpath %.c $(PERIPH)/src
vpath %.c $(DEVICE)
vpath %.c $(NEWLIB)


#  Processor specific

PTYPE = STM32F10X_CL
LDSCRIPT = stm32f100.ld
STARTUP= startup_stm32f10x.o system_stm32f10x.o core_cm3.o sys_calls.o

# compilation flags for gdb

CFLAGS  = -O0 -g

# Compilation Flags
FULLASSERT = -DUSE_FULL_ASSERT
LDFLAGS+= -T$(LDSCRIPT) -nostdlib -static -L$(NEWLIB) -lgcc -mthumb -mcpu=cortex-m3
CFLAGS+=-mcpu=cortex-m3 -mthumb
CFLAGS+= -I. -I$(DEVICE) -I$(CORE) -I$(PERIPH)/inc -I$(NEWLIBINCLUDE) -I.
CFLAGS+= -D$(PTYPE) -DUSE_STDPERIPH_DRIVER 


# Build executable
$(ELF) : $(OBJS)
	$(LD) $(LDFLAGS) -o $@ -lc -lm $(OBJS) -lc -lm -lgcc

# compile and generate dependency info

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	$(CC) -MM $(CFLAGS) $< > $*.d 

%.o: %.s
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(OBJS:.o=.d) $(ELF) 

debug: $(ELF)
	arm-none-eabi-gdb $(ELF)


# pull in dependencies

-include $(OBJS:.o=.d)




