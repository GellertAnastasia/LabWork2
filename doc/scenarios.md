## Use Case Scenarios
### Use Case 1: Placing a Unit on the Battlefield
Precondition: Player 1’s turn, and they have a unit card in their hand.
Actions:

Press the number 1 (select the first card) → Enter.

Enter coordinates (e.g., 3 1) → Enter.
System Checks:

Sufficient mana.

Target cell (3,1) is unoccupied and within the player’s zone.
Result:

The unit is displayed on the battlefield.

Player’s mana is reduced by the card’s cost.

### Use Case 2: Attacking an Opponent’s Object
Precondition: Player 1’s unit is adjacent to Player 2’s object (e.g., at [7,7]).
Actions:

Select the unit → Select the enemy.
System Calculations:

Damage = unit’s attack value.

The object’s health is reduced.
Result:

If the object’s health ≤ 0: the object is removed from the battlefield.

### Use Case 3: Attacking the Opponent’s Base
Precondition: Player 1’s unit is adjacent to Player 2’s base (located at [7,7]).
Actions:

Select the unit → Select the base.
System Calculations:

Damage = unit’s attack value.

The base’s health is reduced.
Result:

If the base’s health ≤ 0: Player 1 wins the game.

### Use Case 4: Purchasing an Additional Card
Precondition: The player has coins ≥ the cost of an additional card.
Actions: Press the number(from the action selection list)
System Checks:

Sufficient coins.
Result:

One card is added to the player’s hand.

Coins are reduced by cost of card.
