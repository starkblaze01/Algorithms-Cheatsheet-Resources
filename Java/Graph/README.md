* Dijkstra
  * If you have the adjacency matrix of a graph:
  ```java
  Dijkstra dijkstra = DijkStra.getInstance(graph);
  ```
  * If you wanted a randomly generated graph:
  ```java
  Dijkstra dijkstra = DijkStra.getInstance(int nodes, int maxLength); // arguements are optional, will be replaced by default values if not passed
  ```
  * If you want to create your own graph:
  ```java
  Dijkstra dijkstra = DijkStra.getInstance(true); // asks for size later
  // or
  Dijkstra dijkstra = Dijkstra.getInstance(true,n); // n is the size
  ```
    then,

  ```java
  Dijkstra.ShortestPath shortestPath = dijkstra.computeFor(sourceNode); // ShortestPath is an inner class

  // Now you can call various methods of ShortestPath

  shortestPath.print(); // prints an overview of the solution
  shortestPath.getDistance(node); // returns distance from specified node to source node
  shortestPath.getPath(node); // returns a List containing the path from the source to the specified node (excluding the node)
  shortestPath.getPaths(); // returns an array of Lists each containing the path from source to the index's node
  shortestPath.getMap(); // returns an Array containing the shortest distances of each node from the source
  ```
<br/>

* GraphGen to generate a graph
  * Use `GraphGen.getRandomGraph(size, maxLength);` to get a Random Unweighted Non-Directional Graph
  * Use `GraphGen.getCustomGraph(size);` to get a Custom Unweighted Non-Directional Graph
  * Use `GraphGen.getDirectionalRandomGraph(size,maxLength)` for Random Unweighted Directional Graph
  * Use `GraphGen.getDirectionalCustomGraph(size)` for Custom Unweighted Directional Graph
  * Use `GraphGen.getWeightedRandomGraph(size,maxLength)` for Random Weighted Non-Directional Graph
  * Use `GraphGen.getWeightedCustomGraph(size)` for Custom Weighted Non-Directional Graph
  * Use `GraphGen.getWeightedDirectionalRandomGraph(size,maxLength)` - go figure
  * Use `GraphGen.getWeightedDirectionalCustomGraph(size)` - go figure