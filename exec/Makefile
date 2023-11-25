# Compiler
CC := g++
# Compiler flags
CFLAGS := -g -Wall -Wextra 
# SFML libraries
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
# Source files
SRC_DIR := ../src
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# Include files
INC_DIR := ../include
INCLUDES := -I$(INC_DIR)
# Library files
LIB_DIR := ../lib
LIB_SRCS := $(wildcard $(LIB_DIR)/*.cpp)
# Object files
OBJ_DIR := build
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
LIB_OBJS := $(patsubst $(LIB_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(LIB_SRCS))
# Output executable
TARGET := app.exe

# Main rule
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS) $(LIB_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(SFML_LIBS)

# Rule to build object files from source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Rule to build object files from library files
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Ensure the build directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean rule
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

.PHONY: all clean
