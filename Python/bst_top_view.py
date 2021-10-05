class Node:
    def __init__(self, info): 
        self.info = info  
        self.left = None  
        self.right = None 
        self.level = None 

    def __str__(self):
        return str(self.info) 

class BinarySearchTree:
    def __init__(self): 
        self.root = None

    def create(self, val):  
        if self.root == None:
            self.root = Node(val)
        else:
            current = self.root
         
            while True:
                if val < current.info:
                    if current.left:
                        current = current.left
                    else:
                        current.left = Node(val)
                        break
                elif val > current.info:
                    if current.right:
                        current = current.right
                    else:
                        current.right = Node(val)
                        break
                else:
                    break


def level(root):
    if (root.left==None and root.right==None):
        return    
    elif (root.left==None):
        root.right.level=root.level+1
        level(root.right)
    elif (root.right==None):
        root.left.level=root.level-1
        level(root.left)
    else:
        root.right.level=root.level+1
        root.left.level=root.level-1
        level(root.left)
        level(root.right)
def topView(root):
    root.level=0
    level(root)
    l=[]
    d={}
    ptr=root
    l.append(ptr)
    while(len(l)):
        ptr=l.pop(0)
        if d.get(ptr.level,None)==None:
            d[ptr.level]=ptr.info
        #print(ptr.info,ptr.level)
        if ptr.left!=None:
            l.append(ptr.left)
        if ptr.right!=None:
            l.append(ptr.right)
    for i in sorted(d.keys()):
        print(d[i],end=" ")


tree = BinarySearchTree()
t = int(input())

arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

topView(tree.root)
