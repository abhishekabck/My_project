class Fancy:
    def __init__(self) -> None:
        self.__seq1 = []
        self.__seq2 = []
        self.__l1 = []
        self.__l2 = []
        self.__inc = 0
        self.__m = 1
    
    @property
    def __length(self):
        return self.__l1 + self.__l2
    
    def append(self, val:int) -> None:
        if self.__length % 2 == 0:
            self.__seq1.append(val)
            self.__l1 += 1
        else :
            self.__seq2.append(val)
            self.__l2 += 1
    
    def addAll(self, inc: int) -> None:
        self.__inc += inc
    
    def multAll(self, m: int) -> None:
        self.__inc *= m
        self.__m *= m
    
    def getIndex(self, idx: int) -> int:
        if self.__length <= idx:
            return -1
        
        elif idx % 2 == 0:
            idx /= 2
            val = self.__seq1[idx]
            val *= self.__m
            val += self.__inc
            return val%(10**9 + 7)
        else :
            idx //=2
            val = self.__seq1[idx]
            val *= self.__m
            val += self.__inc
            return val%(10**9 + 7)
    