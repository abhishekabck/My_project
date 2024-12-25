""" BST(Binary Search Tree):- A binary search tree is a binary tree where each node has a value,
and the left child's value is less than the parent's value, while the right child's value is greater than the parent's value.
"""
# >>> Assumption: All Elements are Distinct <<< #

# defining the Node Structure of the BST
class Node(object):
    def __init__(self) -> object:
        self.data = None
        self.left = None
        self.right = None
    
    def setData(self, data: any) -> None:
        self.data = data
    
    def setLeft(self, node: object) -> None:
        self.left = node
    
    def setRight(self, node: object)-> None:
        self.right = node
    
    def getData(self) -> any:
        return self.data
    
    def remove_left(self) -> None:
        if self.left != None:
            del self.left
        self.left = None
    
    def remove_right(self) -> None:
        if self.right != None:
            del self.right
        self.right = None

# Defining the Structure the Methods of BST
class BST(object):
    def __init__(self) -> None | object:
        self.length = None
        self.root = None
        return None

    def TopView(self, root: object) -> None:
        queue = [root]
        

    def insert(self, data: any) -> None:
        newNode = Node()
        newNode.setData(data)
        # Case 1: If the Binary Search Tree is Empty
        if self.root == None:
            self.root = newNode
        # Case 2: If the Binary Search Tree Consists of only Root Node
        if self.root.left == None and self.root.right == None:
            if self.root.getData() < data:
                self.root.right = newNode
            else:
                self.root.left = newNode
        # case 3: If the BST Contains more than one Element
        temp = self.root
        while temp:
            if temp.data < data:
                if temp.right == None:
                    temp.right = newNode
                else:
                    pass