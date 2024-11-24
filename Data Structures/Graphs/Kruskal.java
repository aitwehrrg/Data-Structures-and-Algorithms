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

        Map<Integer, Set<Edge>> result = kruskal(G);
        int weight = result.keySet().iterator().next();
        System.out.println(weight);
        for (Edge edge : result.get(weight))
            System.out.println(edge);
        scanner.close();
    }
}
