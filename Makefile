CXX           = g++
CXXFLAGS      = -std=gnu++11
####### Output directory
OBJECTS_DIR   = ./
####### Files
SOURCES       = ./main.cpp \
		./led.cpp
TARGET        = ledserv
####### Compile
all: 
	$(CXX) $(SOURCES) -o $(TARGET) $(CXXFLAGS)



