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

    public static void main(String[] args) {
        Graph G = new Graph();
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int n = Integer.parseInt(input[0]), m = Integer.parseInt(input[1]);
        for (int i = 0; i < m; i++) {
            input = scanner.nextLine().split(" ");
            String u = input[0], v = input[1];
            int w = Integer.parseInt(input[2]);
            G.addVertex(u);
            G.addVertex(v);
            G.addEdge(u, v, w);
            G.addEdge(v, u, w);
        }

        Map<Integer, Set<Edge>> result = prim(G);
        int weight = result.keySet().iterator().next();
        System.out.println(weight);
        for (Edge edge : result.get(weight))
            System.out.println(edge);
        scanner.close();
    }
}
