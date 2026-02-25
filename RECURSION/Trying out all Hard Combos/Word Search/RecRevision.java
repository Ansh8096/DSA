package Revision;

import java.util.*;

public class RecRevision {

    private static int checkingNeighbour(String word, int idx, char[][] a, int i, int j, int ansVar, int n, int m, boolean[][] visited) {
        if (idx == word.length()) {
            return 1;
        }

        // checking upward neighbour
        if (i > 0 && ansVar == 0 && visited[i - 1][j] == false) {
            if (a[i - 1][j] == word.charAt(idx)) {
                visited[i - 1][j] = true;
                ansVar = checkingNeighbour(word, idx + 1, a, i - 1, j, ansVar, n, m, visited);
                visited[i - 1][j] = false;
            }
        }

        // checking downward neighbour...
        if (i < n - 1 && ansVar == 0 && visited[i + 1][j] == false) {
            if (a[i + 1][j] == word.charAt(idx)) {
                visited[i + 1][j] = true;
                ansVar = checkingNeighbour(word, idx + 1, a, i + 1, j, ansVar, n, m, visited);
                visited[i + 1][j] = false;
            }
        }

        // checking forward neighbour...
        if (j < m - 1 && ansVar == 0 && visited[i][j + 1] == false) {
            if (a[i][j + 1] == word.charAt(idx)) {
                visited[i][j + 1] = true;
                ansVar = checkingNeighbour(word, idx + 1, a, i, j + 1, ansVar, n, m, visited);
                visited[i][j + 1] = false;
            }
        }

        // checking backward neighbour...
        if (j > 0 && ansVar == 0 && visited[i][j - 1] == false) {
            if (a[i][j - 1] == word.charAt(idx)) {
                visited[i][j - 1] = true;
                ansVar = checkingNeighbour(word, idx + 1, a, i, j - 1, ansVar, n, m, visited);
                visited[i][j - 1] = false;
            }
        }
        return ansVar;
    }

    private static boolean func1(String word) {
        char[][] a = {{'A', 'B', 'C', 'E'},
                {'S', 'F', 'C', 'S'},
                {'A', 'D', 'E', 'E'}
        };

        int idx = 0, ansVar = 0;
        int n = a.length;
        int m = a[0].length;
        boolean[][] visited = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == word.charAt(idx)) {
                    visited[i][j] = true;
                    ansVar = checkingNeighbour(word, idx + 1, a, i, j, 0, n, m, visited);
                    visited[i][j] = false;
                }
                if (ansVar == 1) break;
            }
            if (ansVar == 1) break;
        }
        if (ansVar == 1) return true;
        else return false;
    }


    public static void main(String[] args) {

        // CHECKING IF OUR WORD EXISTS OR NOT IN THE GRID,Problem-19:--------->
        String word = "ABCE";
        System.out.println(func1(word));


    }
}
