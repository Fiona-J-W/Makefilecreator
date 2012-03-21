# Makefile for ../mfc
# created with makefile-creator


####################
#Settings:


CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++0x 
CLIBS = -lboost_filesystem -lboost_system 
INCLUDES = 
TARGET = ../mfc
OBJECTS = ../build/depcheck.o ../build/main.o ../build/mf.o ../build/output.o ../build/settings.o ../build/tools.o ../build/treewalker.o 


####################
#Rules:


$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(CLIBS) $(OBJECTS) -o $(TARGET)

clean:
	rm ../build/*.o

all: $(TARGET)


####################
#Dependencies:


../build/depcheck.o: ./depcheck.cpp ./depcheck.hpp ./tools.hpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c ./depcheck.cpp -o ../build/depcheck.o



../build/main.o: ./main.cpp ./depcheck.hpp ./mf.hpp ./settings.hpp ./tools.hpp ./treewalker.hpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c ./main.cpp -o ../build/main.o



../build/mf.o: ./mf.cpp ./mf.hpp ./settings.hpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c ./mf.cpp -o ../build/mf.o



../build/output.o: ./output.cpp ./output.hpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c ./output.cpp -o ../build/output.o



../build/settings.o: ./settings.cpp ./settings.hpp ./tools.hpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c ./settings.cpp -o ../build/settings.o



../build/tools.o: ./tools.cpp ./tools.hpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c ./tools.cpp -o ../build/tools.o



../build/treewalker.o: ./treewalker.cpp ./tools.hpp ./treewalker.hpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c ./treewalker.cpp -o ../build/treewalker.o



