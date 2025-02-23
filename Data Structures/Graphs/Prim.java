import java.util.*;

public class Prim {
    public static MST prim(Graph G) {
        Set<Edge> mst = new HashSet<>();
        int weight = 0;
        Set<Vertex> visited = new HashSet<>();
        PriorityQueue<Edge> minHeap = new PriorityQueue<>(Comparator.comparingInt(Edge::w));

        Vertex start = G.getVertices().iterator().next();
        visited.add(start);

        minHeap.addAll(G.getAdjacencyList().get(start));
        while (!minHeap.isEmpty()) {
            Edge edge = minHeap.poll();
            if (visited.contains(edge.v()))
                continue;

            mst.add(edge);
            weight += edge.w();
            visited.add(edge.v());
            for (Edge adjacentEdge : G.getAdjacencyList().get(edge.v())) {
                if (!visited.contains(adjacentEdge.v()))
                    minHeap.add(adjacentEdge);
            }
        }

        return new MST(weight, mst);
    }
}
