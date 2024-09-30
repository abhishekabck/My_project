class Node:
    # Constructor
    def __init__(self, data = None, next = None):
        self.data = data
        self.next = data
    # method for setting the data field of the node
    def setData(self, data) -> None:
        self.data = data
    # method of getting the data field of the node
    def getData(self, data) -> any:
        return self.data
    # Method of setting the next field of the node
    def setNext(self, next) -> None:
        self.next = next
    # Method of getting the node points to another node
    def hasNext(self) -> bool:
        return self.next != None

class LinkedList(None):
    # Initializing a list
    def __init__(self, node = Node()):
        self.length = 0
        self.head = node
    
    @property
    def length(self):
        current = self.head
        count = 0
        while current.hasNext:
            count += 1
            current = current.next
        return count
    
    def insertAtBeginning(self, data):
        newNode = Node(data)
        if not self.head.hasNext():
            self.head = newNode
        else:
            newNode.next = self.head
            self.head = newNode
    
    def insertAtEnd(self, data):
        newNode = Node()
        newNode.setData(data)
        current = self.head
        while current.hasNext():
            current = current.next
        current.setNext(newNode)
        self.length += 1
    
    def insertAtGivenPosition(self, pos : int, data : any):
        """
        Args:
            pos (int): Position of new Node in linked list 0 based
            data (any): Data/Element you wish to insert
        Returns:
            None: On Every Cases
        Note:
            In Case when position is Greater than elements in
            linked list the element will be inserted at end
            of linked list
            In Case when position is Less than 0 or 0 the element
            will inserted at beginning of the Linked List
        Complexity:
            Time Complexity :: Worst Case O(n)
            Space Complexity :: O(1)
        """
        if pos >= self.length:
            return self.insertAtEnd(data)
        elif pos <= 0:
            return self.insertAtBeginning(data)
        else:
            newNode = Node(data)
            count = 1
            current = self.head
            while count<pos - 1:
                current = current.next
                count += 1
            newNode.setNext(current.next)
            current.next = newNode
            self.length += 1
    
    def deleteFromBeginning(self) -> bool:
        if self.length == 0:
            return False
        else :
            self.head = self.head.next
            self.length -= 1
        return True
    
    def deleteFromEnd(self) -> bool:
        if self.length == 0:
            return False
        elif self.length == 1:
            self.head = None
            return True
        else:
            current = self.head
            previous = self.head
            while current.next != None:
                previous = current
                current = current.next
            previous.next = None
            self.length -= 1
    
    def deleteFromLinkedListWithNode(self, node):
        pass