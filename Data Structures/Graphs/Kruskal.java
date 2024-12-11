import java.util.*;

public class Kruskal {
    public static MST kruskal(Graph G) {
        Set<Edge> mst = new HashSet<>();
        int weight = 0;
        DisjointSet disjointSet = new DisjointSet(G);

        List<Edge> edges = new ArrayList<>();
        for (Vertex vertex : G.getVertices()) edges.addAll(G.getAdjacencyList().get(vertex));
        edges.sort(Comparator.comparingInt(Edge::w));

        for (Edge edge : edges) {
            Vertex u = edge.u(), v = edge.v();
            if (!disjointSet.connected(u, v)) {
                mst.add(edge);
                weight += edge.w();
                disjointSet.union(u, v);
            }
        }

        return new MST(weight, mst);
    }
}
