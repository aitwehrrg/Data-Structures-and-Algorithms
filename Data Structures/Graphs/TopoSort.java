import java.util.*;

public class TopoSort {
    private static boolean topoSortHelper(Graph G, Vertex vertex, Set<Vertex> visited, Set<Vertex> inStack, Stack<Vertex> stack) {
        visited.add(vertex);
        inStack.add(vertex);

        for (Edge edge : G.getAdjacencyList().get(vertex)) {
            Vertex neighbor = edge.dest();
            if (inStack.contains(neighbor)) return false;
            if (!visited.contains(neighbor))
                if (!topoSortHelper(G, neighbor, visited, inStack, stack))
                    return false;
        }

        inStack.remove(vertex);
        stack.push(vertex);
        return true;
    }

    public static Optional<List<Vertex>> topoSort(Graph G) {
        Set<Vertex> visited = new HashSet<>();
        Set<Vertex> inStack = new HashSet<>();
        Stack<Vertex> stack = new Stack<>();
        List<Vertex> result = new ArrayList<>();

        for (Vertex vertex : G.getVertices()) {
            if (!visited.contains(vertex))
                if (!topoSortHelper(G, vertex, visited, inStack, stack))
                    return Optional.empty();
        }

        while (!stack.isEmpty())
            result.add(stack.pop());

        return Optional.of(result);
    }
}
