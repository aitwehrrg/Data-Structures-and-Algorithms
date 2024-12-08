import java.util.*;

public class Dijkstra {
    private static final int INF = Integer.MAX_VALUE;

    private record Pair(Vertex vertex, int distance) {
        @Override
        public String toString() {
            return vertex + " : " + distance;
        }
    }

    public record Result(Map<Vertex, Integer> distances, Map<Vertex, List<Vertex>> paths) {
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (Vertex vertex : distances.keySet()) {
                String dist = distances.get(vertex) < INF ? Integer.toString(distances.get(vertex)) : "INF";
                sb.append(vertex).append(":\tDistance = ").append(dist).append(",\tPath = ").append(paths.get(vertex)).append("\n");
            }
            return sb.toString();
        }
    }

    public static Result dijkstra(Graph G, Vertex src) {
        PriorityQueue<Pair> minHeap = new PriorityQueue<>(Comparator.comparingInt(Pair::distance));
        Map<Vertex, Integer> distances = new HashMap<>();
        Map<Vertex, Vertex> predecessors = new HashMap<>();
        Set<Vertex> visited = new HashSet<>();

        for (Vertex vertex : G.getVertices()) distances.put(vertex, INF);
        distances.put(src, 0);

        minHeap.add(new Pair(src, 0));
        while (!minHeap.isEmpty()) {
            Vertex current = minHeap.poll().vertex;

            if (visited.contains(current)) continue;
            visited.add(current);

            for (Edge edge : G.getAdjacencyList().get(current)) {
                Vertex neighbor = edge.dest();
                int newDist = distances.get(current) + edge.weight();

                if (newDist < distances.get(neighbor)) {
                    distances.put(neighbor, newDist);
                    predecessors.put(neighbor, current);
                    minHeap.add(new Pair(neighbor, newDist));
                }
            }
        }

        Map<Vertex, List<Vertex>> paths = new HashMap<>();
        for (Vertex vertex : G.getVertices()) {
            List<Vertex> path = new ArrayList<>();
            for (Vertex at = vertex; at != null; at = predecessors.get(at)) path.add(at);
            Collections.reverse(path);
            paths.put(vertex, path);
        }

        return new Result(distances, paths);
    }
}
