class Node:
    def __init__(self) -> None:
        self.data = None
        self.next = None
    
    def setData(self, data):
        self.data = data
    
    def setNext(self, next):
        self.next = next
    
    def getData(self):
        return self.data
    
    def getNext(self):
        return self.next

class Stack(object):
    def __init__(self) -> None:
        self.head = None
        self.last = None
        self.top = -1
    
    def isEmpty(self) -> bool:
        return self.top == -1
    
    def push(self, value):
        if self.isEmpty():
            self.head = Node()
            self.head.setData(value)
            self.last = self.head
        else:
            self.last.next = Node()
            self.last.next.setData(value)
            self.last = self.last.next
        self.top += 1
    
    def pop(self):
        if self.isEmpty():
            print("Stack is Empty")
            return
        current = self.head
        if self.top == 0:
            value = current.getData()
            del current
            self.head = None
            self.last = None
            self.top = self.top - 1
            return value
        cnt = 1
        while cnt < self.top:
            current = current.next
        value = current.getData()
        del current.next
        self.last = current
        self.top -= 1
        return value
    

s = Stack()
s.push(45)
print(s.pop())
print(s.pop())

