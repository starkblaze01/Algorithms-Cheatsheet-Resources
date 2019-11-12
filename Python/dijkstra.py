## This implementation is based on https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
from math import inf

def minDistance(distance, in_shortest_path_tree):
    '''
    Helper function to search for nearest vertex (minimum distance from source) not in the shortest path tree.
    :param distance: Ordered list of distance from a vertex to the source vertex.
    :param in_shortest_path_tree: Ordered list, True if vertex is in the tree and False if not.
    :return: Vertex (integer) with minimum distance from the source that is not already in the shortest path tree.
    '''
    min = inf
    for v in range(len(distance)):
        if distance[v] < min and in_shortest_path_tree[v] == False:
            min = distance[v]
            min_node = v
    return min_node

def dijkstra(graph, source):
    '''
    Implementation of Dijkstra's shortest path algorithm.
    Given a single source vertex, finds the shortest path from the source to each node in a weighted digraph.
    The list distance stores the current distance between a given vertex and the source vertex.
    The list in_shortest_path_tree stores whether a vertex has been included in the tree yet.
    :param graph: A weighted digraph represented by an adjacency matrix (list of lists).
    :param source: An integer denoting the source vertex.
    :return: A list of distances from the source node (the list indices represent the vertices).
    '''

    # Initial distances are infinite as they have not yet been discovered.
    distance = [inf] * len(graph)
    in_shortest_path_tree = [False] * len(graph)
    # Distance from source to source is 0.
    distance[source] = 0

    for node in range(len(graph)):
        # At each step, select the minimum distance vertex from the set of vertices not yet in the shortest path tree.
        u = minDistance(distance, in_shortest_path_tree)

        # Put the minimum distance vertex into the shortest path tree.
        in_shortest_path_tree[u] = True

        # Update distance value of the adjacent vertices of the minimum distance vertex only if the new
        # distance is smaller than the current distance and the adjacent vertex is not in the shortest_path_tree.
        for v in range(len(graph)):
            new_distance = distance[u] + graph[u][v]
            if graph[u][v] > 0 and not in_shortest_path_tree[v] and distance[v] > new_distance:
                distance[v] = new_distance

    print('Vertex\tDistance From Source')
    for i in range(len(graph)):
        print(i, '\t\t\t', distance[i])

    return distance

if __name__ == '__main__':
    # Initialise weighted digraph stored as adjacency matrix.
    # Each list represents a node in the graph and each integer graph[u][v] is the weight of the edge (u, v).
    # If graph[u][v] == 0 there is no edge (u, v)
    graph = [
        [0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 11, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 14, 10, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 2, 0, 1, 6],
        [8, 11, 0, 0, 0, 0, 1, 0, 7],
        [0, 0, 2, 0, 0, 0, 6, 7, 0]
    ]
    distances = dijkstra(graph, 0)
