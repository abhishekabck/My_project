def numberOfAlternatingGroups(colors: list[int]) -> int:
    count = 0
    for i in range(len(colors)-1):
        if (colors[i-1]==colors[i+1] and colors[i-1] != colors[i]):
            count+=1
    if colors[i]==colors[0] and colors[i]!=colors[i+1]:
        count+=1
    return count

print(numberOfAlternatingGroups([1,1,1]))