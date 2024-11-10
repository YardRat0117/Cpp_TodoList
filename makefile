# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Directories
SRC_DIR = src
HEADER_DIR = header
BUILD_DIR = build

# Source and Object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Output executable
EXEC = demo.exe

# Targets

# Default target
all: $(EXEC)

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link object files to create the executable
$(EXEC): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(EXEC)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(HEADER_DIR) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

.PHONY: all clean
