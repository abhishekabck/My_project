import WeightedQuickUF

class percolation:
    # for 1- based indexing
    def __init__(s, n: int):
        # Creating Grid of n-by-n + 2(virtual Nodes) as blocked
        s.grid = [False for i in range(n*n+2)] # false means blocked and True means open
        s.n = n
        s.wuf = WeightedQuickUF.WeightedQuickUnionFind(n*n + 2)
        
    def validate(s, x: int) ->None:
        if x < 1 or x > s.n:
            raise ValueError.add_note("Out of Bound..")
    
    def index(s, row : int, col: int) -> int:
        return (row-1)*s.n + col - 1
        
    def isOpen(s, row : int, col : int) -> bool:
        s.validate(row)
        s.validate(col)
        return s.grid[s.index(row, col)] # returns true is opened
    
    def open(s, row:int , col:int):
        if not s.isOpen(row, col):
            pass