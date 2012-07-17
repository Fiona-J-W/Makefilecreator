# Makefile for ../bin/mfc
# created with makefile-creator


####################
#Settings:


CC = g++
CFLAGS =  -Wall -Wextra -pedantic -O3 -std=c++11 -O0 
CLIBS = -lboost_filesystem -lboost_system 
INCLUDES = 
TARGET = ../bin/mfc
OBJECTS = \
	../build/depcheck.o \
	../build/help.o \
	../build/main.o \
	../build/mf.o \
	../build/output.o \
	../build/settings.o \
	../build/tools.o \
	../build/treewalker.o \



####################
#Rules:


$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(CLIBS)

../build/%.o:
	@if test ! -d '../build'; then mkdir '../build'; echo "created '../build'" ; fi
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm ../build/*.o

all: $(TARGET)


####################
#Dependencies:


../build/depcheck.o: depcheck.cpp depcheck.hpp output.hpp settings.hpp tools.hpp 

../build/help.o: help.cpp help.hpp 

../build/main.o: main.cpp depcheck.hpp help.hpp mf.hpp output.hpp settings.hpp tools.hpp treewalker.hpp 

../build/mf.o: mf.cpp mf.hpp output.hpp settings.hpp tools.hpp 

../build/output.o: output.cpp output.hpp 

../build/settings.o: settings.cpp output.hpp settings.hpp tools.hpp 

../build/tools.o: tools.cpp output.hpp tools.hpp 

../build/treewalker.o: treewalker.cpp output.hpp settings.hpp tools.hpp treewalker.hpp 

