import java.util.*;

public class CycleDetectDirected {
    private static boolean cycleExistsHelper(Graph G, Vertex vertex, Set<Vertex> visited, Set<Vertex> inStack) {
        visited.add(vertex);
        inStack.add(vertex);

        for (Edge edge : G.getAdjacencyList().get(vertex)) {
            Vertex neighbor = edge.dest();
            if (inStack.contains(neighbor)) return true;
            if (!visited.contains(neighbor))
                if (cycleExistsHelper(G, neighbor, visited, inStack))
                    return true;
        }

        inStack.remove(vertex);
        return false;
    }

    public static boolean cycleExists(Graph G) {
        Set<Vertex> visited = new HashSet<>();
        Set<Vertex> inStack = new HashSet<>();

        for (Vertex vertex : G.getVertices()) {
            if (!visited.contains(vertex))
                if (cycleExistsHelper(G, vertex, visited, inStack))
                    return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Graph G = new Graph();
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int n = Integer.parseInt(input[0]), m = Integer.parseInt(input[1]);
        for (int i = 0; i < m; i++) {
            input = scanner.nextLine().split(" ");
            String u = input[0], v = input[1];
            G.addVertex(u);
            G.addVertex(v);
            G.addEdge(u, v, 1);
        }
        System.out.println(cycleExists(G) ? "Cycle detected" : "No cycle detected");
        scanner.close();
    }
}
