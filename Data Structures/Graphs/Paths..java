import java.util.*;

public record Paths(Map<Vertex, Integer> distances, Map<Vertex, List<Vertex>> paths) {
    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        for (Vertex vertex : distances.keySet()) {
            stringBuilder.append(vertex).append(":\tDistance = ").append(distances.get(vertex));
            stringBuilder.append(",\tPath = ").append(paths.get(vertex)).append("\n");
        }
        return stringBuilder.toString();
    }
}
