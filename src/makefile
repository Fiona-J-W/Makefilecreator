# Makefile for bin/mfc
# created with makefile-creator


####################
#Settings:


CXX ?= g++
FLAGS += -std=c++11  -Wall -Wextra -pedantic -std=c++11 
LIBS += -lboost_filesystem -lboost_system 
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
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

../build/%.o:
	@if test ! -d '../build'; then mkdir '../build'; echo "created '../build'" ; fi
	$(CXX) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm ../build/*.o

all: $(TARGET)


####################
#Dependencies:


../build/depcheck.o: ../src/depcheck.cpp ../src/depcheck.hpp ../src/output.hpp ../src/output.tcc ../src/settings.hpp ../src/tools.hpp  src/makefile

../build/help.o: ../src/help.cpp ../src/help.hpp  src/makefile

../build/main.o: ../src/main.cpp ../src/depcheck.hpp ../src/help.hpp ../src/mf.hpp ../src/output.hpp ../src/output.tcc ../src/settings.hpp ../src/tools.hpp ../src/treewalker.hpp  src/makefile

../build/mf.o: ../src/mf.cpp ../src/mf.hpp ../src/output.hpp ../src/output.tcc ../src/settings.hpp ../src/tools.hpp  src/makefile

../build/output.o: ../src/output.cpp ../src/output.hpp ../src/output.tcc  src/makefile

../build/settings.o: ../src/settings.cpp ../src/output.hpp ../src/output.tcc ../src/settings.hpp ../src/tools.hpp  src/makefile

../build/tools.o: ../src/tools.cpp ../src/output.hpp ../src/output.tcc ../src/tools.hpp  src/makefile

../build/treewalker.o: ../src/treewalker.cpp ../src/output.hpp ../src/output.tcc ../src/settings.hpp ../src/tools.hpp ../src/treewalker.hpp  src/makefile

