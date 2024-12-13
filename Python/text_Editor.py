class TextEditor(object):
    # Initializing the Text Editor
    def __init__(self):
        self.string = list()
        self.stack = ['ini']
        
    # Initialzing the append method to add in the string
    def append(self, word, user = "local"):
        self.string.extend(list(word))
        if user == "local":
            self.stack.append([1, len(word)])
    
    # Describing the delete method to remove last k character
    def delete(self, k, user = "local"):
        if user == "local":
            word = self.string[-k:]
            self.stack.append([2, word])
        for x in range(k):
            self.string.pop()
    
    # Describing the print method to print the kth character of the string
    def Print(self, k):
        print(self.string[k-1])
    
    def undo(self):
        last_ops = self.stack.pop()
        if last_ops == 'ini':
            self.string.clear()
            self.stack.append('ini')
        if last_ops[0] == 1:
            self.delete(last_ops[1], user = "admin")
        else:
            self.append(last_ops[1], user = "admin")

def DataTypeHandler(ops):
    if ops.isdigit():
        return int(ops)
    else:
        return str(ops)
            
def main():
    # Initialzing the text Editor
    txtE = TextEditor()
    # Calls
    operations = {1:txtE.append, 2: txtE.delete, 3: txtE.Print, 4: txtE.undo}
    
    q = int(input()) # Number of the inputs
    # reading all the operations
    for i in range(q):
        ops = list(map(DataTypeHandler, input().split()))
        if ops[0] == 4:
            operations[ops[0]]()
        else:
            operations[ops[0]](ops[1])

if __name__ == "__main__":
    main()