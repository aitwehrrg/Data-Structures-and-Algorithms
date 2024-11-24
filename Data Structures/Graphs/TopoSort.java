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

    public static List<Vertex> topoSort(Graph G) {
        Set<Vertex> visited = new HashSet<>();
        Set<Vertex> inStack = new HashSet<>();
        Stack<Vertex> stack = new Stack<>();
        List<Vertex> result = new ArrayList<>();

        for (Vertex vertex : G.getVertices()) {
            if (!visited.contains(vertex))
                if (!topoSortHelper(G, vertex, visited, inStack, stack))
                    return null;
        }

        while (!stack.isEmpty())
            result.add(stack.pop());

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
            G.addVertex(u);
            G.addVertex(v);
            G.addEdge(u, v, 1);
        }

        List<Vertex> result = topoSort(G);
        System.out.println(result == null ? "Cycle detected" : result);
        scanner.close();
    }
}
