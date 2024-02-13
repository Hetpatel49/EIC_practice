# Compiler
CC := gcc

# Directories
SRC_DIR := src
INC_DIR := include
BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)/bin/exe
OBJ_DIR := $(BUILD_DIR)/obj
LIB_DIR := $(BUILD_DIR)/lib

# Files
SRC := $(wildcard $(SRC_DIR)/*.c)
INC := $(wildcard $(INC_DIR)/*.h)
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
EXEC := $(BIN_DIR)/program
LIB := $(LIB_DIR)/libmylib.a

# Compiler flags
CFLAGS := -I$(INC_DIR)

# Rule to create object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the static library
$(LIB): $(OBJ)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

# Rule to build the executable
$(EXEC): $(OBJ) application.c $(LIB)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIB_DIR) -lmylib

# Run the executable
run: $(EXEC)
	./$(EXEC)

# Clean
clean:
	@rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: run clean
