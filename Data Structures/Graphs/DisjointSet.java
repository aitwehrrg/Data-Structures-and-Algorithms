import java.util.*;

public class DisjointSet {
    private final Map<Vertex, Vertex> parent;
    private final Map<Vertex, Integer> rank;

    public DisjointSet(Graph G) {
        this.parent = new HashMap<>();
        this.rank = new HashMap<>();

        for (Vertex vertex : G.getVertices()) {
            parent.put(vertex, vertex);
            rank.put(vertex, 0);
        }
    }

    public boolean union(Vertex u, Vertex v) {
        Vertex rootU = find(u);
        Vertex rootV = find(v);

        if (rootU.equals(rootV))
            return false;

        if (rank.get(rootU) > rank.get(rootV))
            parent.put(rootV, rootU);
        else if (rank.get(rootU) < rank.get(rootV))
            parent.put(rootU, rootV);
        else {
            parent.put(rootV, rootU);
            rank.put(rootU, rank.get(rootU) + 1);
        }
        return true;
    }

    public Vertex find(Vertex u) {
        if (!parent.get(u).equals(u))
            parent.put(u, find(parent.get(u)));
        return parent.get(u);
    }

    public boolean connected(Vertex u, Vertex v) {
        return find(u).equals(find(v));
    }

    @Override
    public String toString() {
        return parent.toString();
    }
}
