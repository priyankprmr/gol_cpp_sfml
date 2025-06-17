# Directories
SRC_DIR = lib
INCLUDE_DIR = include
OBJ_DIR = build/obj
BIN_DIR = build/bin
SFML_DIR = SFML

# Files
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))
TARGET = $(BIN_DIR)/app.exe

# Compiler and flags
CXX = g++
CXXFLAGS = -I$(INCLUDE_DIR) -I$(SFML_DIR)/include
LDFLAGS = -L$(SFML_DIR)/lib -lsfml-graphics -lsfml-window -lsfml-system

# DLLs to copy after build
DLLS = sfml-graphics-3.dll sfml-window-3.dll sfml-system-3.dll
COPY_DLLS = cp $(addprefix $(SFML_DIR)\\bin\\,$(DLLS)) $(subst /,\\,$(BIN_DIR))

# Default target
all: $(BIN_DIR) $(OBJ_DIR) $(TARGET)

# Create bin and obj folders if not exist
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Link object files and copy DLLs
$(TARGET): $(OBJ)
	$(CXX) $^ -o $@ $(LDFLAGS)
	$(COPY_DLLS)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean everything
clean:
	rm -rf build