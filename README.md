# Cathedral of Lost Scripts

A Unity 3D game project featuring a first-person exploration experience with collectible mechanics and environmental interactions.

## Project Overview

Cathedral of Lost is a Unity-based 3D game that combines exploration, collection mechanics, and atmospheric storytelling. Players navigate through mysterious environments, collecting soul fragments while experiencing various sequences and environmental effects.

## Script Organization

The project is organized into the following categories:

### 🎮 Core Systems (`/Core/`)
Core game management and scoring systems:
- **GameManager.cs** - Main game state management and collectible tracking
- **GlobalScore.cs** - Global scoring system for soul collection
- **GlobalTimer.cs** - Game timing and duration tracking
- **LevelScoreManager.cs** - Level-specific scoring management

### 🚶 Player Systems (`/Player/`)
Player movement, interaction, and control:
- **FirstPersonMovementImproved.cs** - Enhanced first-person movement with gravity and ground detection
- **MouseLook.cs** - Mouse-based camera control for first-person view
- **TPMovement.cs** - Third-person movement system
- **Gripper.cs** - Player interaction and grabbing mechanics

### 💎 Collectibles (`/Collectibles/`)
Collectible item systems and behaviors:
- **Collectible.cs** - Base collectible class (commented out - legacy code)
- **CollectGreenGem.cs** - Green gem collection mechanics
- **FragmentCollector.cs** - Soul fragment collection system
- **GemRotate.cs** - Rotating gem animation behavior

### 🖥️ User Interface (`/UI/`)
UI management and display systems:
- **ScoreDisplay.cs** - Score display and UI updates
- **Level2HUD.cs** - Level 2 specific HUD elements
- **MainMenuFunction.cs** - Main menu functionality
- **Credits.cs** - Credits screen management

### 🌍 Environment (`/Environment/`)
Environmental effects and interactions:
- **BellVanish.cs** - Bell disappearing mechanics
- **WallVanish.cs** - Wall disappearing effects
- **Teleport.cs** - Teleportation system

### 🎬 Sequences (`/Sequences/`)
Game sequences and cutscenes:
- **Dialogue Sequence.cs** - Dialogue system management
- **DeathSequence.cs** - Player death sequence handling
- **EndingSequence.cs** - Game ending sequence
- **EndSequence.cs** - Level end sequence
- **FinishSequence.cs** - Level completion sequence
- **SplashToMenu.cs** - Splash screen to main menu transition

## Key Features

- **First-Person Movement**: Smooth character movement with gravity and ground detection
- **Soul Collection System**: Collect soul fragments to progress through levels
- **Environmental Interactions**: Dynamic environment with disappearing objects and teleportation
- **Sequential Storytelling**: Multiple sequence types for narrative progression
- **Score Management**: Comprehensive scoring system across levels
- **UI Integration**: Complete UI system with HUD, menus, and credits

## Technical Details

- **Engine**: Unity 3D
- **Language**: C#
- **Architecture**: Component-based MonoBehaviour system
- **Input**: Keyboard and mouse controls
- **Physics**: Unity's built-in physics system with custom gravity

## Getting Started

1. Import these scripts into a Unity project
2. Set up the appropriate GameObjects and assign the scripts
3. Configure the public variables in the inspector
4. Ensure proper layer masks and tags are set up for ground detection and player interaction

## Dependencies

- Unity 3D (version 2019.4 or later recommended)
- TextMeshPro (for UI text elements)
- Standard Unity Input System

## Notes

- Some scripts contain commented-out code that may be legacy implementations
- Ground detection and jump mechanics are currently disabled in the movement script
- The project uses a mix of first-person and third-person movement systems

## License

This project is part of the "Cathedral of Lost" game development project. Please refer to the main project repository for licensing information.

---

*For questions or contributions, please refer to the main project repository.*
