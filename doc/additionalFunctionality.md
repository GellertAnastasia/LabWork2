# Report on Additional Functionality

## 1. Introduction

Objective:  
Enhance the artificial intelligence (AI) for a turn-based strategy game in C++, where two players compete by destroying the opponent’s base. The original AI was very simple and made random decisions.

---

## 2. Work Performed

### 2.1 Source Code Analysis

Initially, there was a basic class AIControllerEasy that:
- Purchased cards randomly.
- Placed units at random positions.
- Attacked the first encountered enemy without any strategy.

Problems Identified:
1. Random decision-making – the AI acted suboptimally.
2. Lack of error handling – possible segmentation faults when working with empty containers.
3. No tactics – the AI did not defend its base or prioritize targets.

### 2.2 Improved AI Implementation

A new class was created:
- AIControllerNormal (inherits from AIControllerEasy with enhanced logic).

#### Improvements in AIControllerNormal:

| Function             | Previous Behavior                    | New Behavior                                                                 |
|----------------------|--------------------------------------|------------------------------------------------------------------------------|
| selectBestTarget() | Attacked the first enemy             | Prioritizes: base → weak units → dangerous units → nearest to base           |
| aiMoveCharacter()  | Moved to fixed coordinates           | Considers: enemies (pursues), base (attacks)                                 |
| playCard()         | Random card usage                    | Prioritizes: summon units → upgrade strongest → random actions               |
| tryPlaceUnit()     | Random placement                     | Places units closer to the enemy or strategic points                         |
| findNearestEnemy() | Not implemented                      | Finds the nearest enemy for attack or pursuit                                |

Fixed Issues:
- Segmentation Faults
  - Added nullptr checks for all pointers.
  - Added bounds checking for field.grid[y][x].
- Incorrect Upgrades
  - AI no longer tries to upgrade units if none are on the field.
- Pointless Movements
  - Units now move toward the nearest threat or enemy base.

---

## 3. Results

### 3.1 AI Difficulty Levels

| Level  | Description                                                                 |
|--------|-----------------------------------------------------------------------------|
| Easy   | Random but safe actions (no errors).                                        |
| Normal | Tactical decisions: base defense, target prioritization, upgrade strong units.|

---

## 4. Conclusion

- Implemented a systematic AI with two difficulty levels.
- Fixed critical errors (segmentation faults, illogical behavior).
- Added strategic elements (base attack, defense, target prioritization).


