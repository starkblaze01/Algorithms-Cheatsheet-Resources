class BinaryTree:
    
    def __init__(self, obj):
        self.key = obj
        self.leftChild = None
        self.rightChild = None
    
    def insertLeft(self, newNode):
        if self.leftChild == None:
            self.leftChild = BinaryTree(newNode)
            
        else:
            aux = BinaryTree(newNode)
            aux.leftChild = self.leftChild
            self.leftChild = aux
            
            
    def insertRight(self, newNode):
        if self.rightChild == None:
            self.rightChild = BinaryTree(newNode)
            
        else:
            aux = BinaryTree(newNode)
            aux.rightChild = self.rightChild
            self.rightChild = aux
    
    def getRightChild(self):
        return self.rightChild

    def getLeftChild(self):
        return self.leftChild

    def setRootVal(self,obj):
        self.key = obj

    def getRootVal(self):
        return self.key

def inorder(tree):
    if tree != None:
        inorder(tree.getLeftChild())
        print(tree.getRootVal())
        inorder(tree.getRightChild())

if __name__ == "__main__":
    r = BinaryTree('a')
    r.insertLeft('b')
    r.insertRight('c')
    inorder(r)