import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import Utils.GraphGen;

public class Dijkstra {

    // Inner Class to store the Shortest Path for each source node
    class ShortestPath {

        final int V;
        private List<Integer>[] paths;
        private int[] map;

        // Constructors
        ShortestPath(int V) {
            this.V = V;
        }

        ShortestPath(int V, List<Integer>[] paths, int[] map) {
            this.V = V;
            this.paths = paths;
            this.map = map;
        }

        // individual nodes
        public int getDistance(int j) {
            return map[j];
        }

        public List<Integer> getPath(int j) {
            return paths[j];
        }

        // paths
        void setPaths(List<Integer>[] paths) {
            this.paths = paths;
        }

        public List<Integer>[] getPaths() {
            return this.paths;
        }

        // maps
        void setMap(int[] map) {
            this.map = map;
        }

        public void print() {

            System.out.println("\n\nVertex \t\t Distance");

            for (int i = 0; i < V; i++)
                if (map[i] < Integer.MAX_VALUE)
                    System.out.println(i + " \t\t " + map[i] + " through\t" + paths[i].toString());
                else
                    System.out.println(i + " \t\t  No Path ");
        }

        public int[] getMap() {
            return this.map;
        }
    }

    final int V;
    int[][] graph;

    public Dijkstra(int[][] graph) {

        this.graph = graph;
        this.V = graph.length;

    }

    private int closestNode(int dist[], Boolean sptSet[]) {

        int min = Integer.MAX_VALUE, min_index = -1;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }

        return min_index;
    }

    public int computeFor(int src, int dest) {

        return computeFor(src).getDistance(dest);

    }

    @SuppressWarnings("unchecked")
    public ShortestPath computeFor(int src) {

        ShortestPath shortestPath = new ShortestPath(V);

        int dist[] = new int[V];

        List<Integer>[] paths = new ArrayList[V];

        Arrays.fill(paths, new ArrayList<>());

        Boolean sptSet[] = new Boolean[V];

        for (int i = 0; i < V; i++) {
            dist[i] = Integer.MAX_VALUE;
            sptSet[i] = false;
        }

        dist[src] = 0;

        for (int count = 0; count < V - 1; count++) {

            int u = closestNode(dist, sptSet);

            sptSet[u] = true;

            for (int v = 0; v < V; v++)

                if (!sptSet[v] && graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    paths[v] = new ArrayList<>(paths[u]);
                    paths[v].add(u);
                }
        }

        shortestPath.setMap(dist);
        shortestPath.setPaths(paths);

        return shortestPath;
    }

    public static void main(String[] args) {

        int[][] graph2 = new int[][] { { 0, 3, 4, 0, 0, 2 }, { 3, 0, 4, 0, 1, 0 }, { 4, 4, 0, 2, 5, 0 },
                { 0, 0, 2, 0, 5, 0 }, { 0, 1, 5, 5, 0, 2 }, { 2, 0, 0, 0, 2, 0 } };

        Dijkstra g2 = getInstance(graph2);
        Dijkstra.ShortestPath shortestPath = g2.computeFor(3);
        shortestPath.print();

        Dijkstra g1 = getInstance(10);
        g1.computeFor(3, 6);

    }

    public static Dijkstra getInstance(int l, int max) {
        return getInstance(GraphGen.getWeightedRandomGraph(l, max));
    }

    public static Dijkstra getInstance(int l) {
        return getInstance(l, 10);
    }

    public static Dijkstra getInstance() {
        return getInstance(6, 10);
    }

    public static Dijkstra getInstance(boolean custom, int n) {
        if (custom)
            return getInstance(GraphGen.getWeightedCustomGraph(n));
        else
            return getInstance(n);
    }

    public static Dijkstra getInstance(int[][] graph) {
        return new Dijkstra(graph);
    }
}