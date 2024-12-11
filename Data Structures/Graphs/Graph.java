package Graphs;

import java.util.*;

public class Graph {
    private final Map<Vertex, Set<Edge>> adjacencyList;
    private final Map<String, Vertex> vertices;
    private int V, E;

    public Graph() {
        this.adjacencyList = new HashMap<>();
        this.vertices = new HashMap<>();
        this.V = 0; this.E = 0;
    }

    public Vertex addVertex(String label) {
        vertices.putIfAbsent(label, new Vertex(label));
        adjacencyList.putIfAbsent(vertices.get(label), new HashSet<>());
        V = vertices.size();
        return vertices.get(label);
    }

    public Optional<Vertex> getVertex(String label) {
        return Optional.ofNullable(vertices.getOrDefault(label, null));
    }

    public Set<Vertex> getVertices() {
        return adjacencyList.keySet();
    }

    public Edge addEdge(Vertex u, Vertex v, boolean undirected) {
        Edge edge = new Edge(u, v, undirected);
        if (adjacencyList.get(u).add(edge)) E++;
        return edge;
    }

    public Edge addEdge(Vertex u, Vertex v, int w, boolean undirected) {
        Edge edge = new Edge(u, v, w, undirected);
        if (adjacencyList.get(u).add(edge)) E++;
        return edge;
    }

    public Map<Vertex, Set<Edge>> getAdjacencyList() {
        return adjacencyList;
    }

    public int V() {
        return V;
    }

    public int E() {
        return E;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        return adjacencyList.equals(((Graph) o).adjacencyList);
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        for (Vertex vertex : getVertices())
            stringBuilder.append(vertex).append(" : ").append(getAdjacencyList().get(vertex)).append("\n");
        return stringBuilder.toString();
    }
}
