# Node of a singaly linked list
class Node:
    # constructor
    def __init__(self,data = None, next = None):
        self.data = data
        self.next = next
    # method for setting the data field of the node
    def setData(self,data):
        self.data = data
    # method for getting the data field of the node
    def getData(self):
        return self.data
    # method of setting next field of the node
    def setNext(self,next):
        self.next = next
    # method for getting the node points to another node
    def hasNext(self):
        return self.next!=None
# class for defining a liked list
class LinkedList(object):
    # initializing a list
    def __init__(self, node = None):
        self.length = 0
        self.head = node
    
    
    def length(self):
        current = self.head
        count = 0
        while current!=None:
            count += 1
            current = current.next
        return count
    
        """
        Insertion
        """
    def insertAtBeginning(self,data):
        newNode = Node()
        newNode.data = data
        if self.length == 0:
            self.head = newNode
        else:
            newNode.next = self.head
            self.head = newNode
        self.length += 1
    
    ## insertion at end
    def insertAtEnd(self,data):
        newNode = Node()
        newNode.data = data
        current = self.head
        while current.next != None:
            current = current.next
        current.next = newNode
        self.length += 1
    
    ## inserting at random
    def insertAtGivenPosition(self,pos,data):
        """
        Args:
            pos (int): Position of new Node in linked list 
            data (int): Data/Element you wish to insert
        Returns:
            None: On Every Cases
        Note:
            In Case when position is Greater than elements in linked list No changes will be applied
        Complexity:
            Time Complexity :: Worst Case O(n)
            Space Complexity :: O(1)
        """
        if pos>self.length or pos<0:
            return None
        else :
            if pos == 0:
                self.insertAtBeginning(data)
            else :
                if pos == self.length:
                    self.insertAtEnd(data)
                else :
                    newNode = Node()
                    newNode.data = data
                    count = 1
                    current = self.head
                    while count<pos-1:
                        count += 1
                        current = current.next
                    newNode.next = current.next
                    current.next = newNode
                    self.length += 1
                    
    ## Deletion in singly linked list
    def deleteFromBeginning(self):
        if self.length == 0:
            print("The list is Empty")
        else :
            self.head = self.head.next
            self.length -= 1
    
    def deleteFromEnd(self):
        if self.length == 0:
            print("List is Empty")
        else :
            current = self.head
            previous = self.head
            while current.next != None:
                previous = current
                current = current.next
            previous.next = None
            self.length -= 1
    
    # Delete with Node from linked list
    def deleteFromLinkedListWithNode(self,node):
        if self.length == 0:
            raise ValueError("List is empty")
        else:
            current = self.head
            previous = None
            found = False
            while not found:
                if current == node:
                    found = True
                elif current in Node:
                    raise ValueError('Node not in Linked list')
                else :
                    previous = current
                    current = current.next
        if previous in None:
            self.head = current.next
        else :
            previous = current.next 
        self.length -= 1
        
    # Delete with data from linked list
    def deletewithValue(self,value):
        currentnode = self.head
        previousnode = self.head
        while currentnode.next != None or currentnode.data != value:
            if currentnode.value == value:
                previousnode.next = currentnode.next 
                self.length -= 1
                return
            else :
                previousnode = currentnode
                currentnode = currentnode.next
        print("The Value provided is not present")
    
    # Method to delete a node at a particular position
    def deleteAtPosition(self,pos):
        count = 0
        currentnode = self.head
        previousnode = self.head
        if pos>self.length or pos<0:
            print("The position does not exist. Please eneter a valid Position")
        else :
            while currentnode.next != None  or count < pos:
                count += 1
                if count == pos:
                    previousnode.next = currentnode.next
                    self.length -= 1
                    return 
                else:
                    previousnode = currentnode
                    currentnode = currentnode.next
    
    # deleting linked list
    def clear(self):
        temp = self.head
        while temp!=None:
            tt = temp
            temp = temp.next
            del tt
        self.head = None
    
    def reversell(self,head):
        if head == None or head.next == None:
            return head
        else:
            pr_nodes = self.reversell(head.next.next)
            tail = head
            head = head.next
            head.next = tail
            tail.next = None
            if pr_nodes == None:
                return (head,tail)
            else:
                pr_nodes[1].next = head
                return pr_nodes[0],tail

def reverse_list(head):
    prev = None
    current = head

    while current:
        next_node = current.next  # Store the next node
        current.next = prev       # Reverse the current node's pointer
        prev = current            # Move `prev` one step forward
        current = next_node       # Move `current` one step forward

    return prev  # `prev` is the new head of the reversed list

def traverse(head):
    temp = head
    while temp != None:
        print(temp.data, end="->")
        temp = temp.next
    print(temp)

ll = LinkedList()
ll.insertAtBeginning(45)
ll.insertAtBeginning(53)
ll.insertAtEnd(235)
ll.insertAtEnd(243)
traverse(ll.head)
traverse(reverse_list(ll.head))

