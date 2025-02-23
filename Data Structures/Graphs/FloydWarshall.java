import java.util.*;

public class FloydWarshall {
    private static final int INF = Integer.MAX_VALUE;

    private static int[][] deepCopy(int[][] original) {
        if (original == null)
            return null;
        int n = original.length;
        int[][] copy = new int[n][];
        for (int i = 0; i < n; i++)
            copy[i] = Arrays.copyOf(original[i], n);
        return copy;
    }

    public static int[][] floydWarshall(int[][] adjacencyMatrix) {
        int[][] D = deepCopy(adjacencyMatrix);
        int n = D.length;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (D[i][k] < INF && D[k][j] < INF)
                        D[i][j] = Math.min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
        return D;
    }
}
