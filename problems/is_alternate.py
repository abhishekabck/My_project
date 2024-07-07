def is_alternate(colors):
    i , j = 0, len(colors)-1
    while (i<=j):
        if (colors[i] == colors[i+1]) or (colors[j] == colors[j-1]):
            return False
        i,j = i+1,j-1
    return True

print(is_alternate([1,0,1,0,1]))