# Makefile for ../mfc
# created with makefile-creator


####################
#Settings:


CC = g++
CFLAGS =  -Wall -Wextra -pedantic -std=c++11 
CLIBS = -lboost_filesystem -lboost_system 
INCLUDES = 
TARGET = ./../mfc
OBJECTS = \
	./../build/depcheck.o \
	./../build/main.o \
	./../build/mf.o \
	./../build/output.o \
	./../build/settings.o \
	./../build/tools.o \
	./../build/treewalker.o \



####################
#Rules:


$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(CLIBS) -o $(TARGET) $(OBJECTS)

./../build/%.o:
	@if test ! -d ./../build; then mkdir ./../build; echo "created ./../build" ; fi
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm ./../build/*.o

all: $(TARGET)


####################
#Dependencies:


./../build/depcheck.o: ././depcheck.cpp ././depcheck.hpp ././settings.hpp ././tools.hpp 

./../build/main.o: ././main.cpp ././depcheck.hpp ././mf.hpp ././output.hpp ././settings.hpp ././tools.hpp ././treewalker.hpp 

./../build/mf.o: ././mf.cpp ././mf.hpp ././output.hpp ././settings.hpp 

./../build/output.o: ././output.cpp ././output.hpp 

./../build/settings.o: ././settings.cpp ././output.hpp ././settings.hpp ././tools.hpp 

./../build/tools.o: ././tools.cpp ././tools.hpp 

./../build/treewalker.o: ././treewalker.cpp ././output.hpp ././settings.hpp ././tools.hpp ././treewalker.hpp 

