import java.util.*;

public class BellmanFord {
    private static final int INF = Integer.MAX_VALUE;

    public static Optional<Paths> bellmanFord(Graph G, Vertex src) {
        Map<Vertex, Integer> distances = new HashMap<>();
        Map<Vertex, Vertex> predecessors = new HashMap<>();

        for (Vertex vertex : G.getAdjacencyList().keySet()) distances.put(vertex, INF);
        distances.put(src, 0);

        Set<Edge> edges = new HashSet<>();
        for (Vertex vertex : G.getVertices()) edges.addAll(G.getAdjacencyList().get(vertex));

        for (int i = 0; i <= G.V(); i++) {
            for (Edge edge : edges) {
                Vertex u = edge.u(), v = edge.v();
                int w = edge.w();

                if (distances.get(u) < INF && distances.get(u) + w < distances.get(v)) {
                    if (i == G.V()) return Optional.empty();
                    distances.put(v, distances.get(u) + w);
                    predecessors.put(v, u);
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

        return Optional.of(new Paths(distances, paths));
    }
}
