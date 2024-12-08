import java.util.*;

public class APSP {
    private static final int INF = Integer.MAX_VALUE;

    private static int[][] deepCopy(int[][] original) {
        if (original == null) return null;
        int n = original.length;
        int[][] copy = new int[n][];
        for (int i = 0; i < n; i++) copy[i] = Arrays.copyOf(original[i], n);
        return copy;
    }

    private static void extendShortestPaths(int[][] D, int[][] W) {
        int n = D.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++)
                    if (D[i][k] < INF && W[k][j] < INF)
                        D[i][j] = Math.min(D[i][j], D[i][k] + W[k][j]);
            }
        }
    }

    public static int[][] apsp(int[][] adjacencyMatrix) {
        int n = adjacencyMatrix.length;
        int[][] D = new int[n][n];
        int[][] W = deepCopy(adjacencyMatrix);
        for (int i = 0; i < n; i++) {
            Arrays.fill(D[i], INF);
            D[i][i] = 0;
            W[i][i] = INF;
        }

        for (int m = 0; m < n - 1; m++) extendShortestPaths(D, W);
        return D;
    }
}
