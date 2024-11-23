import java.util.*;

public class CycleDetectUndirected {
    private static boolean cycleExistsHelper(Graph G, Vertex src, Set<Vertex> visited) {
        Queue<Vertex> queue = new LinkedList<>();
        Map<Vertex, Vertex> parent = new HashMap<>();

        queue.offer(src);
        visited.add(src);
        parent.put(src, null);

        while (!queue.isEmpty()) {
            Vertex current = queue.poll();
            for (Edge edge : G.getAdjacencyList().get(current)) {
                Vertex neighbor = edge.dest();
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.offer(neighbor);
                    parent.put(neighbor, current);
                } else if (!neighbor.equals(parent.get(current))) return true;
            }
        }
        return false;
    }

    public static boolean cycleExists(Graph G) {
        Set<Vertex> visited = new HashSet<>();
        for (Vertex vertex : G.getVertices()) {
            if (!visited.contains(vertex))
                if (cycleExistsHelper(G, vertex, visited))
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
            G.addEdge(v, u, 1);
        }
        System.out.println(cycleExists(G) ? "Cycle detected" : "No cycle detected");
        scanner.close();
    }
}
