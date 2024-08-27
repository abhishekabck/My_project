def sort(it):
    for i in range(len(it)):
                key = i
                while (key > 0 and it[key-1][0] > it[key][0]):
                    it[key-1], it[key]  = it[key], it[key-1]
                    key -= 1
            
it = [[2,5], [5,2], [0, 3], [9, 7], [-4, 6]]
sort(it)
print(it)