import java.util.*;

public class FloydWarshall {
    private static final int INF = Integer.MAX_VALUE;

    private static int[][] deepCopy(int[][] original) {
        if (original == null) return null;
        int n = original.length;
        int[][] copy = new int[n][];
        for (int i = 0; i < n; i++) copy[i] = Arrays.copyOf(original[i], n);
        return copy;
    }

    private static void printMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            for (int weight : row)
                System.out.print((weight < INF ? weight : "INF") + "\t");
            System.out.println();
        }
    }

    public static int[][] floydWarshall(int[][] adjacencyMatrix) {
        int[][] D = deepCopy(adjacencyMatrix);
        int n = adjacencyMatrix.length;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (D[i][k] < INF && D[k][j] < INF) D[i][j] = Math.min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
        return D;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int[][] adjacencyMatrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            input = scanner.nextLine().split(" ");
            for (int j = 0; j < n; j++)
                adjacencyMatrix[i][j] = input[j].equals("INF") ? INF : Integer.parseInt(input[j]);
        }
        printMatrix(floydWarshall(adjacencyMatrix));
        scanner.close();
    }
}
