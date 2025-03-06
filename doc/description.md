## Overview
А turn-based, tactical strategy game designed for two players competing to destroy each other’s base. Players utilize a combination of unit cards, upgrade cards, and resource management to outmaneuver their opponent. The game emphasizes strategic planning, dynamic resource allocation, and tactical unit control on a grid-based battlefield.

Target Platform: Desktop (Windows/Linux)
Core Technology: C++

## Core Game Mechanics
Turn-Based Gameplay:

Players take alternating turns.

Each turn is divided into phases:
Economy Phase: Acquire resources and draw new cards.
Card Selection: Play cards from hand.
Unit Actions: Move, attack, or use special abilities.


Resource System:
Mana:
Regenerated at the start of each turn.

Spent to play cards 


Coins:
Earned by defeating enemy units or via card effects.

Spent to draw additional cards



Card System:
Unit Cards:
Summon combat units onto the battlefield.

Units have stats: health, attack, movement range, and special ability.


Upgrade Cards:
Enhance existing units.

Can target specific units or global effects.



Battlefield:
Grid Layout: 10x10 cells with predefined spawn zones for characters.

Bases:
Located at opposite ends of the grid.

Base health: 100 HP (reduces when attacked).



Victory Condition:
Destroy the opponent’s base by reducing its health to 0.


## Technical Architecture
Game Engine:
Manages the game loop, turn sequencing, and victory checks.


Battlefield Grid:
Implemented as a 2D array of Cell objects.

## Key Features
Dynamic Card Combos:

Synergies between unit placements and upgrades (e.g., "Knight + Armor Upgrade = +3 defense").


Unit Special Abilities:
Unique actions per unit type (e.g., archers can attack at range, mages heal allies).


Modular Design:
Easy to add new cards/units via JSON configurations.


Visual Feedback:
Animated unit movements, attack effects, and health bars.


## Non-Functional Requirements
Performance:
Target: 60 FPS on mid-tier hardware.

Max turn processing time: 200ms (for AI calculations, if implemented).


Usability:
Intuitive drag-and-drop card interface.

Tooltips for card/unit stats.


Modding Support:
Custom cards/units via JSON files.


## Development Approach
Agile Workflow:
Sprints focused on core subsystems (e.g., "Battlefield Grid MVP," "Card System Integration").


Version Control:
Git for codebase management (branches: dev, feature/card-system, bugfixes).


Testing Strategy:
Unit tests for combat math and resource transactions.

Playtesting with predefined scenarios (e.g., "Base Rush," "Eco Focus").



Game modes:
Bot game mode
Local hot-seat mode (players alternate on the same device).



## Technical Overview
Language: C++17

Output: Terminal/Console (ASCII-based display)

Input Handling: Keyboard via standard input (cin)

Dependencies: Standard Library only

Build System: GNU Make + g++


