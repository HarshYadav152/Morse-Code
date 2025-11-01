CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = morse
SRC = MorseCodeConverter.cpp
OBJ = $(SRC:.cpp=.o)

# Detect OS and set appropriate commands
ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
    RM = del /Q
    RMDIR = rmdir
else
    RM = rm -f
    RMDIR = rm -rf
endif

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    $(RM) $(OBJ) $(TARGET)

run: $(TARGET)
    $(TARGET)

.PHONY: all clean run