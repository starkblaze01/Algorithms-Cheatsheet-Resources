class SimpleGraph:
    def __init__(self):
        self.edges = {}
    
    def neighbors(self, id):
        return self.edges[id]


import collections

class Queue:
    def __init__(self):
        self.elements = collections.deque()
    
    def empty(self):
        return len(self.elements) == 0
    
    def put(self, x):
        self.elements.append(x)
    
    def get(self):
        return self.elements.popleft()


def breadth_first_search(graph, start):
    # print out what we find
    open_list = Queue()
    open_list.put(start)
    visited = {}
    visited[start] = True
    
    while not open_list.empty():
        current = open_list.get()
        print("Visiting %r" % current)
        for next in graph.neighbors(current):
            if next not in visited:
                open_list.put(next)
                visited[next] = True



if __name__ == '__main__':
	example_graph = SimpleGraph()
	example_graph.edges = {
    	'A': ['B'],
    	'B': ['A', 'C', 'D'],
    	'C': ['A'],
    	'D': ['E', 'A'],
    	'E': ['B']
	}
	breadth_first_search(example_graph, 'A')