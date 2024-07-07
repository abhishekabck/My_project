def is_alternate(colors):
    i , j = 0, len(colors)-1
    while (i<=j):
        if (colors[i] == colors[i+1]) or (colors[j] == colors[j-1]):
            return False
        i,j = i+1,j-1
    return True
def numberofalternategroups(colors,k):
    j = len(colors)
    count = 0
    for i in range(j):
        if (i+k)<=j:
            if (is_alternate(colors[i:i+k])):
                count+=1
        else:
            if (is_alternate(colors[i:] + colors[:(i+k+1)%(j+1)])):
                count+=1
    return count
print(numberofalternategroups([0,1,1], k = 3))