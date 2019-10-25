queue = []
def BFS(root, ele):
    global queue

    queue.remove(root)
    
    if(root.children != None):
        for child in root.children:
            queue.append(child)

    if(root.name == ele):
        print(root.name)
    
    elif(len(queue) == 0): print(0)
    
    else:
        BFS(queue[0], ele)

stack = []
def DFS(root, ele):
    return


class Tree(object):
    def __init__(self, name='root', children=None):
        self.name = name
        self.children = None
        
        if children is not None:
            for child in children:
                self.add_child(child)

root = Tree('A')
B = Tree('B')
C = Tree('C')
D = Tree('D')
E = Tree('E')
F = Tree('F')
G = Tree('G')
H = Tree('H')
I = Tree('I')

root.children = [B, C, D]
B.children = [E, F]
C.children = [G, H]
D.children = [I]

# BFS
queue = [root]
BFS(root, 'I')

# DFS
stack = [root]
DFS(root, 'K')
