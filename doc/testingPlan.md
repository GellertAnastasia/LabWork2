# Manaclash Testing Plan

## 1. Core Gameplay Testing

| Test Case                 | Steps                                         | Expected Result                                                      | Automation       |
|---------------------------|-----------------------------------------------|----------------------------------------------------------------------|------------------|
| Correct Starting Conditions | 1. Start a new game<br>2. Check player base positions | Bases are located at opposite corners of the field; each player has 3 cards in hand | Manual           |
| Victory Conditions         | Destroy the opponent’s base                    | Victory screen with statistics appears                               | Manual           |

---

## 2. Card and Resource System Testing

| Test Case                 | Steps                                         | Expected Result                                                      | Automation       |
|---------------------------|-----------------------------------------------|----------------------------------------------------------------------|------------------|
| Mana Consumption on Deployment | 1. Player has 5 mana<br>2. Deploy a card costing 3 mana | Mana decreases to 2                                                  | Unit Tests       |
| Purchasing Additional Cards | 1. Spend 2 coins<br>2. Check the deck         | One card is added to the hand                                        | Integration Tests |

---

## 3. Combat Interaction Testing

| Test Case                 | Steps                                         | Expected Result                                                      | Automation       |
|---------------------------|-----------------------------------------------|----------------------------------------------------------------------|------------------|
| Attack Mechanics           | 1. Character attacks an enemy<br>2. Check health | Damage is calculated as (attack - defense)                          | Manual           |
| Action Blocking           | 1. Use all character actions<br>2. Attempt to act again | Actions are unavailable until the next turn                         | Manual           |

---

## 4. Buildings and Upgrades Testing

| Test Case                 | Steps                                         | Expected Result                                                      | Automation       |
|---------------------------|-----------------------------------------------|----------------------------------------------------------------------|------------------|
| Building Placement         | 1. Use a building card<br>2. Verify position  | Building appears in the specified cell                              | Manual           |
| Applying Upgrades          | 1. Use an upgrade card on a character<br>2. Check stats | Character stats increase according to the upgrade card             | Unit Tests       |
| Placement Zone Restrictions | Attempt to place a building on an occupied cell | Error message is displayed                                          | Manual           |

---

## 5. Interface and Navigation Testing

| Test Case                 | Steps                                         | Expected Result                                                      | Automation       |
|---------------------------|-----------------------------------------------|----------------------------------------------------------------------|------------------|
| Resource Display           | 1. Gain/spend resources<br>2. Check HUD       | Resource counters update in real time                               | Manual           |

---

## 6. Edge Case Testing

| Test Case                 | Steps                                         | Expected Result                                                      | Automation       |
|---------------------------|-----------------------------------------------|----------------------------------------------------------------------|------------------|
| Maximum Number of Units    | Fill the field with characters
