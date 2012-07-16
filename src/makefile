# Makefile for ../bin/mfc
# created with makefile-creator


####################
#Settings:


CC = g++
CFLAGS =  -Wall -Wextra -pedantic -O3 -std=c++11 
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


../build/depcheck.o: depcheck.cpp 

../build/help.o: help.cpp 

../build/main.o: main.cpp 

../build/mf.o: mf.cpp 

../build/output.o: output.cpp 

../build/settings.o: settings.cpp 

../build/tools.o: tools.cpp 

../build/treewalker.o: treewalker.cpp 

