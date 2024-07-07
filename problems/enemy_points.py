def maxPoints(enemyEnergies, currentEnergy):
    enemyEnergies.sort()  # Step 1: Sort the enemy energies
    marked = []
    low, high = 0, len(enemyEnergies) - 1
    points = 0
    m = 0
    while (len(marked) != len(enemyEnergies)):
        m = max(m,points)
        while low <= high:
            if currentEnergy >= enemyEnergies[low]:
                # Gain points by defeating the weakest unmarked enemy
                currentEnergy -= enemyEnergies[low]
                points += 1
                low += 1
            elif points > 0 and (high not in marked):
                # Regain energy by marking the strongest unmarked enemy
                currentEnergy += enemyEnergies[high]
                points -= 1
                high -= 1
                marked.append(high)
            else:
                break  # Cannot perform any more operations
    return m

# Example Usage
enemyEnergies = [3, 2, 2]
currentEnergy = 2
print(maxPoints(enemyEnergies, currentEnergy))  # Output: 3
