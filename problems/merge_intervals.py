class Solution:
    def __sort(self, it):
        for i in range(len(it)):
                key = i
                while (key > 0 and it[key-1][0] > it[key][0]):
                    it[key-1], it[key]  = it[key], it[key-1]
                    key -= 1
    
    def merge(self, it):
        self.__sort(it)
        arr = list()
        arr.append(it[0])
        for i in range(len(it)):
            if arr[-1][1] >= it[i][0] and arr[-1][1] <= it[i][1]:
                arr[-1][1] = it[i][1]
            else:
                arr.append(it[i])
        return arr

s1 = Solution()
inp1 = [[1,3],[2,6],[8,10],[15,18]]
inp2 = [[1,4],[4,5]]
print(s1.merge(inp1))
print(s1.merge(inp2))