import java.util.*;

public class TopoSort {
    private static boolean cycleExists(Graph G, Vertex vertex, Set<Vertex> visited, Set<Vertex> inStack,
            Stack<Vertex> stack) {
        visited.add(vertex);
        inStack.add(vertex);

        for (Edge edge : G.getAdjacencyList().get(vertex)) {
            Vertex neighbor = edge.v();
            if (inStack.contains(neighbor))
                return true;
            if (!visited.contains(neighbor))
                if (cycleExists(G, neighbor, visited, inStack, stack))
                    return true;
        }

        inStack.remove(vertex);
        stack.push(vertex);
        return false;
    }

    public static Optional<List<Vertex>> topoSort(Graph G) {
        Set<Vertex> visited = new HashSet<>();
        Set<Vertex> inStack = new HashSet<>();
        Stack<Vertex> stack = new Stack<>();
        List<Vertex> result = new ArrayList<>();

        for (Vertex vertex : G.getVertices()) {
            if (!visited.contains(vertex))
                if (cycleExists(G, vertex, visited, inStack, stack))
                    return Optional.empty();
        }

        while (!stack.isEmpty())
            result.add(stack.pop());

        return Optional.of(result);
    }
}
