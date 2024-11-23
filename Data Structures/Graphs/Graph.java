import java.util.*;

public class Graph {
    private final Map<Vertex, Set<Edge>> adjacencyList;
    private final Map<String, Vertex> vertices;

    public Graph() {
        this.adjacencyList = new HashMap<>();
        this.vertices = new HashMap<>();
    }

    public void addVertex(String label) {
        vertices.putIfAbsent(label, new Vertex(label));
        adjacencyList.putIfAbsent(vertices.get(label), new HashSet<>());
    }

    public Vertex getVertex(String label) {
        return vertices.getOrDefault(label, null);
    }

    public Set<Vertex> getVertices() {
        return adjacencyList.keySet();
    }

    public void addEdge(String uLabel, String vLabel, int w) {
        Vertex u = vertices.get(uLabel);
        Vertex v = vertices.get(vLabel);
        adjacencyList.computeIfAbsent(u, _ -> new HashSet<>()).add(new Edge(u, v, w));
    }

    public Map<Vertex, Set<Edge>> getAdjacencyList() {
        return adjacencyList;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Map.Entry<Vertex, Set<Edge>> entry : adjacencyList.entrySet())
            sb.append(entry.getKey()).append(" : ").append(entry.getValue()).append("\n");
        return sb.toString();
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
        }
        System.out.println(G.getAdjacencyList());
        scanner.close();
    }
}
