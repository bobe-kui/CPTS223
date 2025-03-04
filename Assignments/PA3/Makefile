# Compiler
CXX = g++
CXXFLAGS = -g -Wall -std=c++11

# Source files
SRCS = main.cpp functions.cpp USCity.cpp
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = pa3

# Default target
all: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compiling step for each .cpp
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
