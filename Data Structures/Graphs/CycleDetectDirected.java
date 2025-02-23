import java.util.*;

public class CycleDetectDirected {
    private static boolean cycleExistsHelper(Graph G, Vertex vertex, Set<Vertex> visited, Set<Vertex> inStack) {
        visited.add(vertex);
        inStack.add(vertex);

        for (Edge edge : G.getAdjacencyList().get(vertex)) {
            Vertex neighbor = edge.v();
            if (inStack.contains(neighbor))
                return true;
            if (!visited.contains(neighbor))
                if (cycleExistsHelper(G, neighbor, visited, inStack))
                    return true;
        }

        inStack.remove(vertex);
        return false;
    }

    public static boolean cycleExists(Graph G) {
        Set<Vertex> visited = new HashSet<>();
        Set<Vertex> inStack = new HashSet<>();

        for (Vertex vertex : G.getVertices()) {
            if (!visited.contains(vertex))
                if (cycleExistsHelper(G, vertex, visited, inStack))
                    return true;
        }
        return false;
    }
}
