class Node:
    def __init__(self):
        self.previous = None
        self.data = None
        self.next = None
    
    def setData(self, data):
        self.data = data
    
    def setNext(self, Next):
        self.next = Next
    
    def setPrevious(self, previous):
        self.previous = previous
    
    def getData(self):
        return self.data
    
    def getNext(self):
        return self.next
    
    def getPrevious(self):
        return self.previous
    

class Stack(object):
    def __init__(self, *args):
        self.top = None
        self.length = 0
        for x in args:
            self.push(x)
    
    def push(self, data):
        if self.top == None:
            self.top = Node()
            self.top.setData(data)
        else:
            self.top.next = Node()
            self.top.next.setData(data)
            self.top.next.previous = self.top
            self.top = self.top.next
        self.length += 1
    
    def pop(self):
        if self.top == None:
            print("Stack is Empty")
            return None
        else :
            val = self.top.getData()
            temp = self.top
            self.top = self.top.previous
            del temp
            if self.top != None:
                self.top.next = None
        self.length -= 1
        return val
        
    def _isEmpty_(self):
        return self.top == None

s = Stack(6,5,4,3,5,"Hello",4,3,5,3)
for x in range(20):
    print(s.pop())
