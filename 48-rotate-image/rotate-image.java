class Solution {
    public void rotate(int[][] matrix) {

        // Uses EXTRA Space

        /*
        int n = matrix.length;
        int copy[][] = new int[n][n];

        int col = 0;

        for(int i = 0; i<n; i++) {
            int row = n-1;
            for(int j = 0; j<n; j++) {
                copy[i][j] = matrix[row][col];
                row--;
            }
            col++;
        }

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                matrix[i][j] = copy[i][j];
            }
        }
        */

        // IN-PLACE

        int n = matrix.length;

        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n/2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-1-j] = temp;
            }
        }
    }
}