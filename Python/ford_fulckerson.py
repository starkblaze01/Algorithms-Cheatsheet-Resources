# Python - Ford Fulckerson Algo 

# Adjacency matrix representation for Directed graph
class Graph: 
    # Constructor
	def __init__(self,graph): 
		self.graph = graph # residual graph 
		self. ROW = len(graph) 

	'''Returns true if there is a path from source 's' to sink 't' in 
	residual graph. Also fills parent[] to store the path '''
	def BFS(self,s, t, parent): 

		# Mark all the vertices as not visited 
		visited =[False]*(self.ROW) 
		
		# Create a queue for BFS 
		queue=[] 
		
		# Mark the source node as visited and enqueue it 
		queue.append(s)
		visited[s] = True
		
		# Standard BFS Loop 
		while queue: 

			#Dequeue a vertex from queue and print it 
			u = queue.pop(0) 
		
			# Get all adjacent vertices of the dequeued vertex u 
			# If a adjacent has not been visited, then mark it 
			# visited and enqueue it 
			for ind, val in enumerate(self.graph[u]): 
				if visited[ind] == False and val > 0 : 
					queue.append(ind) 
					visited[ind] = True
					parent[ind] = u 

		# If we reached sink in BFS starting from source, then return 
		# true, else false 
		return True if visited[t] else False
			
	
	# Returns tne maximum flow from s to t in the given graph 
	def FordFulkerson(self, source, sink): 

		# This array is filled by BFS and to store path 
		parent = [-1]*(self.ROW) 

		max_flow = 0 # There is no flow initially 

		# Augment the flow while there is path from source to sink 
		while self.BFS(source, sink, parent) : 

			# Find minimum residual capacity of the edges along the 
			# path filled by BFS. Or we can say find the maximum flow 
			# through the path found. 
			path_flow = float("Inf") 
			s = sink 
			while(s != source): 
				path_flow = min (path_flow, self.graph[parent[s]][s]) 
				s = parent[s] 

			# Add path flow to overall flow 
			max_flow += path_flow 

			# update residual capacities of the edges and reverse edges 
			# along the path 
			v = sink 
			while(v != source): 
				u = parent[v] 
				self.graph[u][v] -= path_flow 
				self.graph[v][u] += path_flow 
				v = parent[v] 

		return max_flow 


# Create a graph given in the above diagram 

		
R = int(input('Enter the number of verices(Length of the graph)\n'))
print('Enter the elements in the graph seperated by a new line(press enter after each input)')
graph=[]

# For user input 
for i in range(R):          # A for loop for row entries 
    a =[] 
    for j in range(R):      # A for loop for column entries 
         a.append(int(input())) 
    graph.append(a) 

g = Graph(graph) 

source = 0; sink = R-1

print ("The maximum possible flow is %d " % g.FordFulkerson(source, sink)) 
