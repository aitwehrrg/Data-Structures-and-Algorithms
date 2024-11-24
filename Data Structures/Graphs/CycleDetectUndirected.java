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
}
