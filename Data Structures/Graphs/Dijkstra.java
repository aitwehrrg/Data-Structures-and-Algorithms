import java.util.*;

public class Dijkstra {
    private static final int INF = Integer.MAX_VALUE;

    private record Pair(Vertex vertex, int distance) {
        @Override
        public String toString() {
            return vertex + " : " + distance;
        }
    }

    public static Map<Vertex, Integer> dijkstra(Graph G, Vertex src) {
        PriorityQueue<Pair> minHeap = new PriorityQueue<>(Comparator.comparingInt(Pair::distance));
        Map<Vertex, Integer> distances = new HashMap<>();
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
                    minHeap.add(new Pair(neighbor, newDist));
                }
            }
        }
        return distances;
    }
}
