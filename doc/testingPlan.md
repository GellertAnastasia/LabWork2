## Testing Plan for "ManaClash"  
### 1. Unit Testing  
Objective: Verify the functionality of individual components.  
Test Cases:  
- Cards:  
  - Activating a unit card with sufficient mana:  
    *Expected:* Unit appears on the field, mana decreases.  
  - Activating a card without mana:  
    *Expected:* Card is not activated, "Not enough mana" error.  
- Resources:  
  - Granting coins for killing a unit:  
    *Expected:* Player's coins increase by the unit's bounty value.  
  - Purchasing a card for 3 coins:  
    *Expected:* Card is added to the hand, coins decrease by 3.  
- Units:  
  - Moving a unit to a valid cell:  
    *Expected:* Unit's position updates.  
  - Attacking a target within range:  
    *Expected:* Target's health decreases by the unit's attack value.  

---

### 2. Integration Testing  
Objective: Verify system interactions.  
Test Cases:  
- Card Activation → Unit Placement → Base Attack:  
  *Expected:* After placing a unit, the player attacks the base, reducing its health.  
- Economy + Cards:  
  - Killing a unit → Granting coins → Purchasing a card.  
  *Expected:* New card appears in the hand.  
- AI Bot:  
  - AI places a unit → Attacks the player.  
  *Expected:* AI actions follow logical strategies.  

---

### 3. System Testing  
Objective: Verify the full game cycle.  
Test Cases:  
- Winning by Destroying the Base:  
  Player attacks the base until its health reaches 0.  
  *Expected:* "Victory!" message appears.  
- Turn Transition:  
  Player ends turn → Turn passes to the opponent.  
  *Expected:* Opponent's resources (mana) refresh.  

---

### 4. UI Testing  
Objective: Verify console data rendering.  
Test Cases:  
- Field Rendering:  
  Units display as symbols (e.g., `W`), empty cells as dots.  
- Resource Display:  
  After earning coins: Coins: 5 → 8.  
- Card Selection Interface:  
  Cards in hand are numbered (1, 2, 3...).  

---

### 5. Error Handling Testing  
Objective: Verify responses to invalid actions.  
Test Cases:  
- Placing a Unit Outside the Field:  
  *Expected:* "Invalid coordinates" error.  
- Attacking Out of Range:  
  *Expected:* "Target out of reach" error.  
- Purchasing a Card Without Coins:  
  *Expected:* "Not enough coins" error.  

---

### 6. Balance Testing  
Objective: Ensure gameplay balance.  
Test Cases:  
- Card Costs:  
  Verify that powerful units require more mana.  
- Unit Efficiency:  
  10 attacks from a basic unit should destroy the base (100 HP / 10 damage per attack).  

---

### 7. Cross-Platform Testing  
Objective: Verify functionality across OSes.  
Test Cases:  
- Build and Launch:  
  Linux (g++), macOS (Clang), Windows (WSL + MinGW).  

---

### 8. Test Automation  
Tools:  
- Google Test for C++ unit tests.  
- Scripts for gameplay scenario verification.  
Example Test:  
TEST(EconomyTest, CoinRewardOnKill) {  
    Player player;  
    Unit enemy(UnitType::WARRIOR, 10 /* bounty */);  
    player.OnUnitKilled(enemy);  
    ASSERT_EQ(player.GetCoins(), 10);  
}  

---

### 9. Reporting  
- Logging: Record results for each test.  
- Bug Reports: Document unexpected behavior with reproduction steps.  

---
