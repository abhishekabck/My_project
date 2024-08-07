import WeightedQuickUF
class percolation:
    def __init__(self, grid_size: int):
        # Calling WeightedQuickUnionFind class to connect opened blocks
        # Taking two extra blocks for virtual top and virtual top\
        self.gs = grid_size
        self.wuf = WeightedQuickUF.WeightedQuickUnionFind(self.gs*self.gs + 2)
        self.status = [0 for i in range(self.gs*self.gs)]    # Taking all the blockes of matrix as blocked
        self.vt = self.gs*self.gs + 1
        self.vb = self.vt + 1
    
    def validate(self, row: int, col: int) -> bool:
        if row < 1 and row > self.gs or col < 1 and col > self.gs:
            return False
        return True
    
    def ind(self, row:int , col: int) -> int:
        return (row - 1) * self.gs + (col - 1)
            
    def open(self, row: int, col: int) -> None:
        if self.validate(row, col) == True:
            raise ValueError.add_note("Incorrect Index.")
        index = self.ind(row, col)
        self.status[index] = 1
        if row == 1 or row == self.gs:
            if row == 1:
                self.wuf.union(self.vt, index)
            else:
                self.wuf.union(index, self.vb)
        else:
            if self.status[index - self.gs] == 1: # checking Upward block
                self.wuf.union(index - self.gs, index)
            if self.status[index - 1] == 1: # checking for backward block
                self.wuf.union(index - 1, index)
            if self.status[index + 1] == 1: # checking for forward block
                self.wuf.union(index, index + 1)
            if self.status[index + self.gs] == 1:  # checking for downward block
                self.wuf.union(index, index + self.gs)
    
    def isOpen(self, row: int, col:int) -> bool:
        if not self.validate(row, col):
            raise ValueError.add_note("Incorrect Index")
        return self.status[self.ind(row, col)]
    
    def isFull(self, row: int, col: int):
        if not self.validate(row, col):
            raise ValueError.add_note("Incorrect Index")
        index = self.ind(row, col)
        if self.gs == 1:
            return self.status[index]
        
        elif row != self.gs:
            return self.wuf.connected(self.vt, index)
        
        else:
            if self.status[index - self.gs] == 1:
                return True
            elif col > 1 and self.status[index - 1] == 1:
                return self.isFull(row, col - 1)
            
    
    def isPeroclates(self, row: int, col: int) -> bool:
        pass
    