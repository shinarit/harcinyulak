CC = g++
CPP = $(CC)

OBJS = main.o controller.o map.o bunny.o custom_init.o commandline_options.o
CONTROLLERS = 

ifdef SystemRoot
  RM = del /Q /S
  EXE = nyuszik.exe
  DEFS  =
  INCLUDES	= -I. 
  LIBS = -lmingw32
else
  RM = rm -rf
  EXE = nyuszik
  DEFS = -DSTANDALONE -DHAVE_CONFIG_H -DHAVE_GTK2
  INCLUDES = -I. 
  LIBS = 
endif

CFLAGS += -std=c++0x -Wall -Weffc++ -pedantic -U__STRICT_ANSI__ -g 

default: nyuszik

all: nyuszik

nyuszik: $(OBJS) $(CONTROLLERS)
	$(CPP) -g -o nyuszik $(OBJS) $(LIBS)

%.o: %.cpp
	$(CPP) -c -o $@ $(CFLAGS) $(INCLUDES) $<

clean:
	$(RM) *.o $(EXE) core

