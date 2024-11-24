import java.util.*;

public class Prim {
    public static Map<Integer, Set<Edge>> prim(Graph G) {
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

        Map<Integer, Set<Edge>> result = new HashMap<>();
        result.put(weight, mst);
        return result;
    }
}
