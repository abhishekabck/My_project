
position = [5,4,3,2,1]
health = [2,17,9,15,10]
direction = list('RRRRR')
positionSize = len(position)
class Solution:
    def survivedRobotsHealths(self, position: List[int], health: List[int], direction: str) -> List[int]:
        positionSize = len(position)
        direction = list(direction)
        dr = {i:-1 for i in position}
        for j in range(positionSize):
            for i in range(positionSize -1- j):
                if position[i]>position[i+1]:
                    position[i],position[i+1] = position[i+1], position[i]
                    health[i],health[i+1] = health[i+1], health[i]
                    direction[i], direction[i+1] = direction[i+1], direction[i]

        stack = []
        for i in range(positionSize):
            if (len(stack) == 0) or (direction[i] == stack[-1][1]) or direction[i] == "R":
                stack.append([health[i],direction[i],position[i]])
            elif health[i] == stack[-1][0]:
                stack.pop()
            elif health[i] > stack[-1][0]:
                stack.pop()
                stack.append([health[i]-1, direction[i],position[i]])
            else:
                stack[-1][0] -= 1
        # sorting according to order
        for i in stack:
            dr[i[2]] = i[0]
        health = []
        health = [dr[i] for i in dr if dr[i]!= -1]
        return health
