class Fancy:
    def __init__(self) -> None:
        self.__seq1 = []
        self.__seq2 = []
        self.__inc = [0]
        self.__m = [1]
    
    @property
    def __length(self):
        return len(self.__seq1) + len(self.__seq2)
    
    def append(self, val:int) -> None:
        self.__seq.append(val)
        self.__inc.append(self.__inc[-1])
        self.__m.append(self.__m[-1])
    
    def addAll(self, inc: int) -> None:
        self.__inc[-1] += inc
    
    def multAll(self, m: int) -> None:
        self.__inc[-1] *= m
        self.__m[-1] *= m
    
    def getIndex(self, idx: int) -> int:
        if self.__length <= idx:
            return -1
        
        
    