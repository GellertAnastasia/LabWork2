# Manaclash Testing Results ✅

## 1. Core Gameplay Testing

| Test Case                  | Test Result                                                                                                  | Test Type          | Status |
|----------------------------|--------------------------------------------------------------------------------------------------------------|--------------------|--------|
| Correct Starting Conditions | Verified: bases are correctly placed in opposite corners of the field; each player has 3 cards in hand. No issues found. | Manual             | ✅     |
| Victory Conditions          | Upon destroying the opponent’s base, the victory screen with statistics appears correctly. No issues detected. | Manual             | ✅     |

---

## 2. Card and Resource System Testing

| Test Case                  | Test Result                                                                                                  | Test Type          | Status |
|----------------------------|--------------------------------------------------------------------------------------------------------------|--------------------|--------|
| Mana Consumption on Deployment | Mana correctly decreases from 5 to 2 when deploying a card costing 3 mana. No issues found.                  | Unit Tests         | ✅     |
| Purchasing Additional Cards | Spending 2 coins adds 1 card to the hand. Process works smoothly without bugs.                               | Integration Tests  | ✅     |

---

## 3. Combat Interaction Testing

| Test Case                  | Test Result                                                                                                  | Test Type          | Status |
|----------------------------|--------------------------------------------------------------------------------------------------------------|--------------------|--------|
| Attack Mechanics            | Damage is correctly calculated as (attack - defense). Health updates without errors.                         | Manual             | ✅     |
| Action Blocking            | After using all character actions, further actions in the same turn are unavailable. No issues found.        | Manual             | ✅     |

---

## 4. Buildings and Upgrades Testing

| Test Case                  | Test Result                                                                                                  | Test Type          | Status |
|----------------------------|--------------------------------------------------------------------------------------------------------------|--------------------|--------|
| Building Placement          | Buildings appear in the selected cells without errors.                                                      | Manual             | ✅     |
| Applying Upgrades           | Character stats increase according to the upgrade card. No issues detected.                                 | Unit Tests         | ✅     |
| Placement Zone Restrictions | Attempting to place a building on an occupied cell triggers a correct error message.                          | Manual             | ✅     |

---

## 5. Interface and Navigation Testing

| Test Case                  | Test Result                                                                                                  | Test Type          | Status |
|----------------------------|--------------------------------------------------------------------------------------------------------------|--------------------|--------|
| Resource Display            | Mana and coin values update in the HUD in real time without delays or errors.                               | Manual             | ✅     |

---

## 6. Edge Case Testing

| Test Case                  | Test Result                                                                                                  | Test Type          | Status |
|----------------------------|--------------------------------------------------------------------------------------------------------------|--------------------|--------|
| Maximum Number of Units| When the field is filled with characters, new cards cannot be placed. The system correctly blocks further placement. | Manual             | ✅     |

---

All tests were successfully completed without any bugs. The game is stable and meets the specified requirements.
