# Compiler
CXX = g++
CXXFLAGS = -g -Wall -std=c++14

# Source files
SRCS = main.cpp Destination.cpp ListMyJosephus.cpp TestListMyJosephus.cpp VectorMyJosephus.cpp TestVectorMyJosephus.cpp
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = pa2

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
