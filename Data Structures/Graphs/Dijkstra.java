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
            Pair currentPair = minHeap.poll();
            Vertex current = currentPair.vertex;

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
        String src = scanner.next();
        Map<Vertex, Integer> distances = dijkstra(G, G.getVertex(src));
        for (Vertex vertex : G.getVertices())
            System.out.println(vertex + " : " + distances.get(vertex));
        scanner.close();
    }
}
