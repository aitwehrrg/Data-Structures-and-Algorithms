import java.util.*;

public class BFS {
    public static List<Vertex> bfs(Graph G, Vertex src) {
        Set<Vertex> visited = new HashSet<>();
        Queue<Vertex> queue = new LinkedList<>();
        List<Vertex> result = new ArrayList<>();

        queue.offer(src);
        visited.add(src);
        while (!queue.isEmpty()) {
            Vertex vertex = queue.poll();
            result.add(vertex);
            for (Edge edge : G.getAdjacencyList().get(vertex)) {
                if (!visited.contains(edge.dest())) {
                    queue.offer(edge.dest());
                    visited.add(edge.dest());
                }
            }
        }
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
        String src = scanner.next();
        System.out.println(bfs(G, G.getVertex(src)));
        scanner.close();
    }
}
