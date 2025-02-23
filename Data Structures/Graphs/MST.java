import java.util.*;

public record MST(int weight, Set<Edge> mst) {
    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder(Integer.toString(weight)).append("\n");
        for (Edge edge : mst)
            stringBuilder.append(edge).append("\n");
        return stringBuilder.toString();
    }
}
