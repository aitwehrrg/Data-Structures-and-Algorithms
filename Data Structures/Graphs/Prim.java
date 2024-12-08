import java.util.*;

public class Prim {
    public record MST(int weight, Set<Edge> mst) {
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder().append(weight);
            for (Edge edge : mst) sb.append("\n").append(edge);
            return sb.toString();
        }
    }

    public static MST prim(Graph G) {
        Set<Edge> mst = new HashSet<>();
        int weight = 0;
        Set<Vertex> visited = new HashSet<>();
        PriorityQueue<Edge> minHeap = new PriorityQueue<>(Comparator.comparingInt(Edge::weight));

        Vertex start = G.getVertices().iterator().next();
        visited.add(start);

        minHeap.addAll(G.getAdjacencyList().get(start));
        while (!minHeap.isEmpty()) {
            Edge edge = minHeap.poll();
            if (visited.contains(edge.dest())) continue;

            mst.add(edge);
            weight += edge.weight();
            visited.add(edge.dest());
            for (Edge adjacentEdge : G.getAdjacencyList().get(edge.dest())) {
                if (!visited.contains(adjacentEdge.dest()))
                    minHeap.add(adjacentEdge);
            }
        }

        return new MST(weight, mst);
    }
}
