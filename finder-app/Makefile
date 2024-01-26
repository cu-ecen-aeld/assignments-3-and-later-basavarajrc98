
# Makefile for the "writer" application

# Compiler
CC := gcc

# Cross-compiler prefix
CROSS_COMPILE :=

# Compiler flags
CFLAGS := -Wall -Wextra -pedantic

# Source files
SRC := writer.c

# Object files
OBJ := $(SRC:.c=.o)

# Target binary
TARGET := writer

# Default target
all: $(TARGET)

# Build the application
$(TARGET): $(OBJ)
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files
%.o: %.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
clean:
	rm -f $(TARGET) $(OBJ)

.PHONY: all clean
