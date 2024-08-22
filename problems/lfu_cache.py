class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.catch = dict()
        self.size = 0
        self.usage = dict()
        self.lru = dict()
        self.step = 0

    def get(self, key: int) -> int:
        if key not in self.catch:
            return -1 # return -1 if the element is not present
        # Code if the key is present
        self.usage[key] += 1 # Increasing usage of key by 1
        self.step += 1  # incresing the Step by 1
        self.lru[key] = self.step  # Assigning the step as key's value to get the least frequently between frequency keys
        return self.catch[key] # return value of key
    
    def mfkey(self):
        m = sorted(self.usage.values())[0]
        ls = []
        for key in self.usage:
            if self.usage[key] == m:
                ls.append(key)
        return ls
        


    def put(self, key: int, value: int) -> None:
        if self.size<self.capacity and key not in self.catch:
            self.catch[key] = value
            self.step+=1
            self.lru[key] = self.step
            self.usage[key] = 1
            self.size += 1
        elif key in self.catch:
            self.catch[key] = value
            self.step+=1
            self.lru[key] = self.step
            self.usage[key] += 1
        elif key not in self.catch and self.size>=self.capacity:
            ls = self.mfkey()
            mn = ls[0]
            for ky in ls:
                if self.lru[ky] < self.lru[mn]:
                    mn = ky
            self.usage.pop(mn)
            self.lru.pop(mn)
            self.catch.pop(mn)
            self.catch[key] = value
            self.step += 1
            self.lru[key] = self.step
            self.usage[key] = 1


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

file1 = open(r"C:\Users\Public\Documents\Projects\problems\input.txt","r")
file2 = open(r"C:\Users\Public\Documents\Projects\problems\input2.txt","r")
data1 = eval(file1.read())
data2 = eval(file2.read())
file1.close()
file2.close()

with open("output.txt","w") as file:
    lf = LFUCache(data2[0][0])
    for i in range(1, len(data1)):
        if data1[i] == "get":
            file.write(str(lf.get(data2[i][0])))
        elif data1[i] == "put":
            file.write(str(lf.put(data2[i][0], data2[i][1])))
        file.write("\n")
        print("case::-::",i)
