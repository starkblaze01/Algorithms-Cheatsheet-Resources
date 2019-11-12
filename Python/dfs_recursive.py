class SimpleGraph:
    def __init__(self):
        self.edges = {}

    @property
    def nodes(self):
        return self.edges.keys()

    def neighbors(self, id):
        return self.edges[id]

class DFS(object):
    '''
    Implementation of recursive depth-first search algorithm
    Note for status 0=not visited, 1=seen but not done, 2=done
    '''
    def __init__(self, graph):
        self.graph = graph
        self.status = {k:0 for k in graph.nodes}
        self.predecessors = {k:None for k in graph.nodes}
        self.seen = {k: 0 for k in graph.nodes}
        self.done = {k: 0 for k in graph.nodes}
        self.t = 0

    def dfs_visit_recursive(self, s):
        self.status[s] = 1
        self.seen[s] = self.t
        self.t += 1
        neighbours = self.graph.neighbors(s)
        for v in neighbours:
            if self.status[v] == 0:
                self.predecessors[v] = s
                self.dfs_visit_recursive(v)
        self.status[s] = 2
        self.done[s] = self.t
        self.t += 1

    def search(self):
        '''
        Searches the graph in depth-first order
        :return: dict of seen-times and done-times of nodes
        '''
        for node in self.graph.nodes:
            if self.status[node] == 0:
                self.dfs_visit_recursive(node)
        return self.seen, self.done

if __name__ == '__main__':
    example_graph = SimpleGraph()
    example_graph.edges = {
    	'A': ['B'],
    	'B': ['A', 'C', 'D'],
    	'C': ['A'],
    	'D': ['E', 'A'],
    	'E': ['B']
    }
    print(DFS(example_graph).search())

