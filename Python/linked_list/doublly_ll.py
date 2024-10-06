class node:
    def __init__(self, previous = None, data = None, next = None) -> None:
        self.previous = previous
        self.data = data
        self.next = next
    
    def getData(self) -> any:
        pass