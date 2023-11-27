# Compiler
CC := g++
# Compiler flags
CFLAGS := -Wall -Wextra -Werror -std=c++11 -arch arm64
# SFML library path
SFML_LIB_PATH := -L/opt/homebrew/Cellar/sfml/2.6.1/lib
SFML_INCLUDE := -I/opt/homebrew/Cellar/sfml/2.6.1/include
# SFML libraries
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
# Source files
SRC_DIR := ../src
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# Include files
INC_DIR := ../include
INCLUDES := -I$(INC_DIR) $(SFML_INCLUDE)
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
	$(CC) $(CFLAGS) $^ -o $@ $(SFML_LIB_PATH) $(SFML_LIBS) -arch arm64

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

# Run rule
run: $(TARGET)
	export DYLD_LIBRARY_PATH=$(SFML_LIB_PATH) && ./$(TARGET)

.PHONY: all clean run