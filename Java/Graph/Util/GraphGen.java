package Graph.Util;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class GraphGen {

    public static void printGraph(int[][] graph) {
        for (int i = 0; i < graph.length; i++) {
            System.out.println(Arrays.toString(graph[i]));
        }
    }

    public static Graph getGraph(int[][] graph) {
        return new Graph(graph);
    }

    // Returns a Random Unweighted Non-Directional Graph
    public static int[][] getRandomGraph(int n, int max) {

        int[][] temp = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double huh = Math.random();

                if (huh > 0.55) {
                    temp[i][j] = 1;
                    temp[j][i] = 1;
                }
            }

        }

        return temp;

    }

    // Returns a Custom Unweighted Non-Directional Graph
    public static int[][] getCustomGraph(int n) {

        Scanner scanner = new Scanner(System.in);

        int[][] temp = new int[n][n];

        for (int i = 0; i < temp.length; i++) {

            System.out.println("Enter connections for " + i + ": [-1 breaks, and no need to repeat");

            while (true) {

                int c = scanner.nextInt();

                if (c < 0)
                    break;

                if (c < n) {
                    temp[i][c] = 1;
                    temp[c][i] = 1;
                }

            }
        }

        scanner.close();

        return temp;
    }

    // Returns a Random Unweighted Directional Graph
    public static int[][] getDirectionalRandomGraph(int n, int max) {

        int[][] temp = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i == j)
                    continue;

                double huh = Math.random();

                if (huh > 0.55) {
                    temp[i][j] = 1;
                }
            }

        }

        return temp;

    }

    // Returns a Custom Unweighted Directional Graph
    public static int[][] getDirectionalCustomGraph(int n) {

        Scanner scanner = new Scanner(System.in);

        int[][] temp = new int[n][n];

        for (int i = 0; i < temp.length; i++) {

            System.out.println("Enter connections for " + i + ": [-1 breaks]");

            while (true) {

                int c = scanner.nextInt();

                if (c < 0)
                    break;

                if (c < n)
                    temp[i][c] = 1;

            }
        }

        scanner.close();

        return temp;
    }

    // Returns a Random Weighted Non-Directional Graph
    public static int[][] getWeightedRandomGraph(int n, int max) {

        int[][] temp = new int[n][n];

        Random r = new Random();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double toAdd = r.nextDouble();

                if (toAdd > 0.55) {

                    int rNode = r.nextInt(max);

                    temp[i][j] = rNode;
                    temp[j][i] = rNode;
                }
            }

        }

        return temp;

    }

    // Returns a Custom Weighted Non-Directional Graph
    public static int[][] getWeightedCustomGraph(int n) {

        Scanner scanner = new Scanner(System.in);

        int[][] temp = new int[n][n];

        for (int i = 0; i < temp.length; i++) {

            System.out.println("Enter connections for " + i + ": [-1 breaks, and no need to repeat");

            while (true) {
                System.out.print("Node: ");
                int c = scanner.nextInt();

                if (c < 0)
                    break;

                if (c < n) {

                    System.out.print("Weight: ");
                    int w = scanner.nextInt();
                    temp[i][c] = w;
                    temp[c][i] = w;
                }

            }
        }

        scanner.close();

        return temp;
    }

    // Returns a Random Weighted Directional Graph
    public static int[][] getWeightedDirectionalRandomGraph(int n, int max) {

        int[][] temp = new int[n][n];

        Random r = new Random();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i == j)
                    continue;

                if (r.nextDouble() > 0.49)
                    temp[i][j] = r.nextInt(max);

            }

        }

        return temp;

    }

    // Returns a Custom Weighted Directional Graph
    public static int[][] getWeightedDirectionalCustomGraph(int n) {

        Scanner scanner = new Scanner(System.in);

        int[][] temp = new int[n][n];

        for (int i = 0; i < temp.length; i++) {

            System.out.println("Enter connections for " + i + ": [-1 breaks]");

            while (true) {
                System.out.print("Node: ");
                int c = scanner.nextInt();

                if (c < 0)
                    break;

                if (c < n) {

                    System.out.print("Weight: ");
                    int w = scanner.nextInt();
                    temp[i][c] = w;
                }

            }
        }

        scanner.close();

        return temp;
    }

}

class Graph {

    final int V;
    List<Integer>[] connectivity;

    public Graph(int[][] nodes) {
        this(nodes, nodes.length);
    }

    @SuppressWarnings("unchecked")
    public Graph(int[][] nodes, int V) {
        this.V = V;

        this.connectivity = new List[V];

        for (int i = 0; i < V; i++)
            this.connectivity[i] = new ArrayList<>();

    }

    public void addEdge(int u, int v) {
        this.connectivity[u].add(v);
        this.connectivity[v].add(u);
    }

    public Graph(int V) {
        this(new int[V][V], V);
    }

}

class DirectionalGraph extends Graph {

    public DirectionalGraph(int[][] nodes) {
        super(nodes, nodes.length);
    }

    public DirectionalGraph(int[][] nodes, int V) {
        super(nodes, V);

    }

    public DirectionalGraph(int V) {
        super(V);
    }

    @Override
    public void addEdge(int u, int v) {
        this.connectivity[u].add(v);
    }

}
