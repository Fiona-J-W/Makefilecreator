# Makefile for ../mfc
# created with makefile-creator


####################
#Settings:


CC = g++
CFLAGS =  -Wall -Wextra -pedantic -O3 -std=c++11 
CLIBS = -lboost_filesystem -lboost_system 
INCLUDES = 
TARGET = mfc
OBJECTS = \
	build/depcheck.o \
	build/main.o \
	build/mf.o \
	build/output.o \
	build/settings.o \
	build/tools.o \
	build/treewalker.o \



####################
#Rules:


$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(CLIBS) -o $(TARGET) $(OBJECTS)

build/%.o:
	@if test ! -d 'build'; then mkdir 'build'; echo "created 'build'" ; fi
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm build/*.o

all: $(TARGET)


####################
#Dependencies:


build/depcheck.o: src/depcheck.cpp src/depcheck.hpp src/settings.hpp src/tools.hpp 

build/main.o: src/main.cpp src/depcheck.hpp src/mf.hpp src/output.hpp src/settings.hpp src/tools.hpp src/treewalker.hpp 

build/mf.o: src/mf.cpp src/mf.hpp src/output.hpp src/settings.hpp src/tools.hpp 

build/output.o: src/output.cpp src/output.hpp 

build/settings.o: src/settings.cpp src/output.hpp src/settings.hpp src/tools.hpp 

build/tools.o: src/tools.cpp src/output.hpp src/tools.hpp 

build/treewalker.o: src/treewalker.cpp src/output.hpp src/settings.hpp src/tools.hpp src/treewalker.hpp 

