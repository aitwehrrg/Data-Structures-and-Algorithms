import java.util.*;

public class Kosaraju {
    private static void dfs(Graph G, Vertex src, Set<Vertex> visited, Stack<Vertex> stack) {
        visited.add(src);
        for (Edge edge : G.getAdjacencyList().get(src)) {
            Vertex neighbor = edge.v();
            if (!visited.contains(neighbor))
                dfs(G, neighbor, visited, stack);
        }
        stack.push(src);
    }

    private static Graph reverse(Graph G) {
        Graph H = new Graph();
        for (Vertex vertex : G.getVertices())
            for (Edge edge : G.getAdjacencyList().get(vertex)) {
                Vertex u = edge.u(), v = edge.v();
                int w = edge.w();
                H.addEdge(H.addVertex(v.label()), H.addVertex(u.label()), w, false);
            }
        return H;
    }

    private static void collectSCC(Graph G, Vertex src, Set<Vertex> visited, Set<Vertex> component) {
        visited.add(src);
        component.add(src);
        for (Edge edge : G.getAdjacencyList().get(src)) {
            Vertex neighbor = edge.v();
            if (!visited.contains(neighbor))
                collectSCC(G, neighbor, visited, component);
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
