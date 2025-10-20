# Cathedral of Lost Scripts

A first-person puzzle collectathon game implemented in C, featuring environmental interactions, collectible systems, and narrative sequences.

## Overview

This project is a complete C implementation of a Unity-style game engine with core gameplay systems including collectible mechanics, environmental interactions, player movement, and UI sequences. Originally developed as a Unity C# project, it has been fully converted to C while maintaining all original functionality.

## Project Structure

```
├── src/
│   ├── main.c                    # Main program entry point and demo
│   ├── collectible.h/c           # Collectible pickup system
│   ├── core/                     # Core game systems
│   │   ├── game_manager.h/c      # Level management and collectible counting
│   │   └── global_score.h/c      # Global score tracking
│   ├── player/                   # Player systems
│   │   └── movement.h/c          # First-person movement controller
│   ├── environment/              # Environmental interactions
│   │   └── environment.h/c       # Teleport, WallVanish, BellVanish mechanics
│   ├── sequences/                # UI and sequence systems
│   │   └── sequences.h/c         # Dialogue and finish sequences
│   └── utils/                    # Utility systems
│       └── unity_types.h/c       # Unity-like type definitions and utilities
├── Makefile                      # Build configuration
└── README.md                     # This file
```

## Features

### 🎮 Core Gameplay
- **Collectible System**: Trigger-based pickup detection with sound effects and level counters
- **Score Management**: Per-level and global score tracking with HUD updates
- **Progression Gates**: Bell-activated mechanics that unlock after collecting all items

### 🌍 Environment Interactions
- **Teleportation**: Instant movement between designated points
- **Wall Vanishing**: Dynamic wall removal with audio feedback
- **Bell Gates**: Conditional progression based on collection completion

### 🎯 Player Systems
- **First-Person Movement**: CharacterController-based movement system
- **Input Handling**: Framework for keyboard/mouse input processing
- **Physics Integration**: Ground detection and gravity system (framework)

### 🎬 UI Sequences
- **Dialogue System**: Input-blocking popup sequences with timed confirmation
- **Finish Sequences**: End-of-level transitions with audio and scene management
- **HUD Management**: Dynamic UI updates during gameplay and sequences

## Building and Running

### Prerequisites
- GCC compiler (4.9+)
- Make utility
- Standard C99 library

### Quick Start
```bash
# Build the project
make

# Build and run
make run

# Clean build artifacts
make clean

# Debug build with additional flags
make debug

# Release build with optimizations
make release
```

### Manual Compilation
```bash
gcc -Wall -Wextra -std=c99 -g -Isrc -Isrc/core -Isrc/player -Isrc/environment -Isrc/sequences -Isrc/utils \
    src/main.c src/utils/unity_types.c src/core/game_manager.c src/core/global_score.c \
    src/collectible.c src/player/movement.c src/environment/environment.c src/sequences/sequences.c \
    -o cathedral_game

./cathedral_game
```

## Architecture

### Design Patterns
- **Component System**: Modular game objects with composable behaviors
- **Event-Driven**: Trigger-based interactions and callbacks
- **State Management**: Centralized game state with per-system updates

### Key Conversions from Unity C#
- **Classes → Structures**: C# MonoBehaviour classes became C structs with associated functions
- **Properties → Functions**: C# properties converted to getter/setter function pairs
- **Inheritance → Composition**: C# inheritance replaced with composition and function pointers
- **Garbage Collection → Manual Memory**: C# automatic memory management replaced with malloc/free

### Memory Management
- All objects use explicit allocation/deallocation
- Proper cleanup in destroy functions
- Null pointer checks throughout
- No memory leaks in demo execution

## Usage Example

```c
#include "core/game_manager.h"
#include "collectible.h"
#include "utils/unity_types.h"

int main() {
    // Create game objects
    GameObject player = {0};
    strcpy(player.tag, "Player");
    player.active = true;
    
    // Initialize systems
    GameManager* manager = GameManager_Create(10, NULL);
    CollectGreenGem* gem = CollectGreenGem_Create(&player);
    gem->gameManager = manager;
    
    // Simulate gameplay
    CollectGreenGem_OnTriggerEnter(gem, &player);
    
    // Cleanup
    GameManager_Destroy(manager);
    CollectGreenGem_Destroy(gem);
    
    return 0;
}
```

## Technical Details

### Compilation
- **Standard**: C99 compliant
- **Warnings**: All warnings enabled (-Wall -Wextra)
- **Debugging**: Debug symbols included (-g)
- **Include Paths**: Organized header structure with proper include directories

### Performance
- **Memory**: Minimal memory footprint with efficient struct layouts
- **CPU**: Lightweight function calls with no virtual dispatch overhead
- **I/O**: Console-based output for demonstration purposes

### Limitations
This implementation is designed as a demonstration and has several limitations compared to a full game engine:

1. **No Graphics Rendering** - Console output only
2. **No Physics Engine** - Collision detection is simulated
3. **No Audio Playback** - Audio calls are logged to console
4. **No Input System** - Input is simulated in demo
5. **No Scene Management** - Scene loading is simulated
6. **No Coroutines** - Delayed actions are simplified

## Development

### Adding New Features
1. Create header file in appropriate `src/` subdirectory
2. Implement corresponding `.c` file
3. Update `Makefile` with new source files
4. Add include paths as needed

### Code Style
- **Naming**: PascalCase for types, snake_case for functions
- **Headers**: Include guards with `#ifndef`/`#define`
- **Documentation**: Function comments with parameter descriptions
- **Error Handling**: Null pointer checks and debug output

## License

This project is available for educational and demonstration purposes.

## Contributing

This is a demonstration project. For questions or suggestions, please refer to the code comments and documentation within the source files.
