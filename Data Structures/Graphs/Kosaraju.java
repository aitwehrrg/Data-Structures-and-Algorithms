import java.util.*;

public class Kosaraju {
    private static void dfs(Graph G, Vertex src, Set<Vertex> visited, Stack<Vertex> stack) {
        visited.add(src);
        for (Edge edge : G.getAdjacencyList().get(src)) {
            Vertex neighbor = edge.dest();
            if (!visited.contains(neighbor))
                dfs(G, neighbor, visited, stack);
        }
        stack.push(src);
    }

    private static Graph reverse(Graph G) {
        Graph H = new Graph();
        for (Vertex vertex : G.getVertices())
            for (Edge edge : G.getAdjacencyList().get(vertex)) {
                Vertex u = edge.src(), v = edge.dest();
                int w = edge.weight();
                H.addEdge(H.addVertex(v.label()), H.addVertex(u.label()), w);
            }
        return H;
    }

    private static void collectSCC(Graph H, Vertex src, Set<Vertex> visited, Set<Vertex> component) {
        visited.add(src);
        component.add(src);
        for (Edge edge : H.getAdjacencyList().get(src)) {
            Vertex neighbor = edge.dest();
            if (!visited.contains(neighbor))
                collectSCC(H, neighbor, visited, component);
        }
    }

    public static Set<Set<Vertex>> kosaraju(Graph G) {
        Set<Vertex> visited = new HashSet<>();
        Stack<Vertex> stack = new Stack<>();
        for (Vertex vertex : G.getVertices()) {
            if (!visited.contains(vertex))
                dfs(G, vertex, visited, stack);
        }

        Graph H = reverse(G);

        visited.clear();
        Set<Set<Vertex>> sccs = new HashSet<>();
        while (!stack.isEmpty()) {
            Vertex vertex = stack.pop();
            if (!visited.contains(vertex)) {
                Set<Vertex> scc = new HashSet<>();
                collectSCC(H, vertex, visited, scc);
                sccs.add(scc);
            }
        }
        return sccs;
    }
}
