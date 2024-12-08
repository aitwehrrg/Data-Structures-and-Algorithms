import java.util.*;

public class Kruskal {
    public record MST(int weight, Set<Edge> mst) {
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder().append(weight);
            for (Edge edge : mst) sb.append("\n").append(edge);
            return sb.toString();
        }
    }

    public static MST kruskal(Graph G) {
        Set<Edge> mst = new HashSet<>();
        int weight = 0;
        DisjointSet disjointSet = new DisjointSet(G);

        List<Edge> edges = new ArrayList<>();
        for (Vertex vertex : G.getVertices()) edges.addAll(G.getAdjacencyList().get(vertex));
        edges.sort(Comparator.comparingInt(Edge::weight));

        for (Edge edge : edges) {
            Vertex u = edge.src(), v = edge.dest();
            if (!disjointSet.connected(u, v)) {
                mst.add(edge);
                weight += edge.weight();
                disjointSet.union(u, v);
            }
        }

        return new MST(weight, mst);
    }
}
