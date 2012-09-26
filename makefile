# Makefile for bin/mfc
# created with makefile-creator


####################
#Settings:


CC = g++
CFLAGS =  -Wall -Wextra -pedantic -O3 -std=c++11 
CLIBS = -lboost_filesystem -lboost_system 
INCLUDES = 
TARGET = bin/mfc
OBJECTS = \
	build/depcheck.o \
	build/help.o \
	build/main.o \
	build/mf.o \
	build/output.o \
	build/settings.o \
	build/tools.o \
	build/treewalker.o \



####################
#Rules:


$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(CLIBS)

build/%.o:
	@if test ! -d 'build'; then mkdir 'build'; echo "created 'build'" ; fi
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm build/*.o

all: $(TARGET)


####################
#Dependencies:


build/depcheck.o: src/depcheck.cpp src/depcheck.hpp src/output.hpp src/output.tcc src/settings.hpp src/tools.hpp 

build/help.o: src/help.cpp src/help.hpp 

build/main.o: src/main.cpp src/depcheck.hpp src/help.hpp src/mf.hpp src/output.hpp src/output.tcc src/settings.hpp src/tools.hpp src/treewalker.hpp 

build/mf.o: src/mf.cpp src/mf.hpp src/output.hpp src/output.tcc src/settings.hpp src/tools.hpp 

build/output.o: src/output.cpp src/output.hpp src/output.tcc 

build/settings.o: src/settings.cpp src/output.hpp src/output.tcc src/settings.hpp src/tools.hpp 

build/tools.o: src/tools.cpp src/output.hpp src/output.tcc src/tools.hpp 

build/treewalker.o: src/treewalker.cpp src/output.hpp src/output.tcc src/settings.hpp src/tools.hpp src/treewalker.hpp 

