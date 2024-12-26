# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Source files
SRCS = DNodeG.cpp IteratorG.cpp Range.cpp NodeDictionaryG.cpp Entry.cpp EnglishDictionary.cpp main.cpp

# Header files
HEADERS = DNodeG.h IteratorG.h Range.h NodeDictionaryG.h Entry.h EnglishDictionary.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = main

# Default rule to build the executable
all: $(TARGET)

# Rule to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

# PHONY targets
.PHONY: all clean