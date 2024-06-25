n = 6
meetings = [[1,2,5],[2,3,8],[1,5,10]]
firstPerson = 1
all_people = {0,firstPerson}

# Sorting 
l = len(meetings) - 1
for i in range(l-1):
    for j in range(l-i):
        if meetings[j][2] > meetings[j+1][2]:
            meetings[j],meetings[j+1] = meetings[j+1],meetings[j]

print(meetings)