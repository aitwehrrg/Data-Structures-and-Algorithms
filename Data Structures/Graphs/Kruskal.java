import java.util.*;

public class Kruskal {
    public static Map<Integer, Set<Edge>> kruskal(Graph G) {
        Set<Edge> mst = new HashSet<>();
        int weight = 0;
        UnionFind unionFind = new UnionFind(G);

        List<Edge> edges = new ArrayList<>();
        for (Vertex vertex : G.getVertices()) edges.addAll(G.getAdjacencyList().get(vertex));

        edges.sort(Comparator.comparingInt(Edge::weight));
        for (Edge edge : edges) {
            Vertex u = edge.src(), v = edge.dest();
            if (!unionFind.connected(u, v)) {
                mst.add(edge);
                weight += edge.weight();
                unionFind.union(u, v);
            }
        }

        Map<Integer, Set<Edge>> result = new HashMap<>();
        result.put(weight, mst);
        return result;
    }
}
