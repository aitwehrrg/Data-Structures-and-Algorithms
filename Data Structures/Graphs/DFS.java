import java.util.*;

public class DFS {
    public static List<Vertex> dfs(Graph G, Vertex src) {
        Set<Vertex> visited = new HashSet<>();
        Stack<Vertex> stack = new Stack<>();
        List<Vertex> result = new ArrayList<>();

        stack.push(src);
        visited.add(src);
        while (!stack.isEmpty()) {
            Vertex vertex = stack.pop();
            result.add(vertex);
            for (Edge edge : G.getAdjacencyList().get(vertex)) {
                if (!visited.contains(edge.dest())) {
                    stack.push(edge.dest());
                    visited.add(edge.dest());
                }
            }
        }
        return result;
    }
}
