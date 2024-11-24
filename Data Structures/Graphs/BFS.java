import java.util.*;

public class BFS {
    public static List<Vertex> bfs(Graph G, Vertex src) {
        Set<Vertex> visited = new HashSet<>();
        Queue<Vertex> queue = new LinkedList<>();
        List<Vertex> result = new ArrayList<>();

        queue.offer(src);
        visited.add(src);
        while (!queue.isEmpty()) {
            Vertex vertex = queue.poll();
            result.add(vertex);
            for (Edge edge : G.getAdjacencyList().get(vertex)) {
                if (!visited.contains(edge.dest())) {
                    queue.offer(edge.dest());
                    visited.add(edge.dest());
                }
            }
        }
        return result;
    }
}
