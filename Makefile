# Makefile for Cathedral of Lost Scripts C Implementation

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -Isrc -Isrc/core -Isrc/player -Isrc/environment -Isrc/sequences -Isrc/utils
TARGET = cathedral_game
SOURCES = src/main.c src/utils/unity_types.c src/core/game_manager.c src/core/global_score.c src/collectible.c src/player/movement.c src/environment/environment.c src/sequences/sequences.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = src/utils/unity_types.h src/core/game_manager.h src/core/global_score.h src/collectible.h src/player/movement.h src/environment/environment.h src/sequences/sequences.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Compile source files to object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CFLAGS += -DDEBUG -O0
debug: $(TARGET)

# Release build
release: CFLAGS += -O2 -DNDEBUG
release: $(TARGET)

# Install dependencies (if any)
install:
	@echo "No external dependencies required for this C implementation"

# Help
help:
	@echo "Available targets:"
	@echo "  all      - Build the executable (default)"
	@echo "  clean    - Remove build artifacts"
	@echo "  run      - Build and run the program"
	@echo "  debug    - Build with debug flags"
	@echo "  release  - Build with release optimization"
	@echo "  install  - Install dependencies"
	@echo "  help     - Show this help message"

.PHONY: all clean run debug release install help
