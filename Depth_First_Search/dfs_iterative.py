#find if a certain number is connected to another thru the graph
class Node:

    def __init__(self, val):
        self.val = val
        self.neighboors = set()

class Graph:

    def __init__(self):

        self.nodes = {}
    
    def add_neighboor(self,node1, node2):
        if node1 not in self.nodes:
            new_node = Node(node1)
            self.nodes[node1] = new_node
        if node2 not in self.nodes:
            new_node = Node(node2)
            self.nodes[node2] = new_node
        self.nodes[node1].neighboors.add(node2)
        self.nodes[node2].neighboors.add(node1)
    
    def dfs(self, begin, end):

        if begin == end:
            return True

        stack = [begin]
        visited = {begin}

        while stack:

            num = stack.pop()
            
            for nb in self.nodes[num].neighboors:
                if nb == end:
                    return True
                if nb not in visited:
                    stack.append(nb)
                    visited.add(nb)
        
        return False

if __name__ == "__main__":

    g = Graph()
    g.add_neighboor(1,2)
    g.add_neighboor(1,3)
    g.add_neighboor(4,3)
    g.add_neighboor(4,7)
    g.add_neighboor(5,8)

    print(g.dfs(1,7), g.dfs(1,8)) # returns True and False

        
        