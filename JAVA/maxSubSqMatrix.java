// Find the size of the largest square submatrix of 1’s present in a binary matrix
// For Example--INPUT
//   0   0   1   0   1   1
//   0   1   1   1   0   0
//   0   0   1   1   1   1
//   1   1   0   1   1   1
//   1   1   1   1   1   1
//   1   1   0   1   1   1
//   1   0   1   1   1   1
//   1   1   1   0   1   1
//     OUTPUT-3

import java.util.concurrent.atomic.AtomicInteger;
 
class Main
{
    // Function to find the size of the largest square submatrix of 1's
    // present in a given binary matrix
    public static int findLargestSquare(int[][] mat, int m, int n, AtomicInteger maxsize)
    {
        // base condition
        if (m == 0 || n == 0)
        {
            if (maxsize.get() != 0) {
                maxsize.set(Integer.max(maxsize.get(), mat[m][n]));
                return mat[m][n];
            }
 
            for (int i = 0; i <= m; i++) {
                if (mat[i][n] == 1) {
                    maxsize.set(1);
                    break;
                }
            }
 
            for (int j = 0; j <= n; j++) {
                if (mat[m][j] == 1) {
                    maxsize.set(1);
                    break;
                }
            }
 
            return maxsize.get();
        }
 
        // find the largest square matrix ending at mat[m][n-1]
        int left = findLargestSquare(mat, m, n - 1, maxsize);
 
        // find the largest square matrix ending at mat[m-1][n]
        int top = findLargestSquare(mat, m - 1, n, maxsize);
 
        // find the largest square matrix ending at mat[m-1][n-1]
        int diagonal = findLargestSquare(mat, m - 1, n - 1, maxsize);
 
        /* The largest square matrix ending at mat[m][n] will be 1 plus
            minimum of largest square matrix ending at mat[m][n-1],
            mat[m-1][n] and mat[m-1][n-1] */
 
        int size = 0;
        if (mat[m][n] != 0) {
            size = 1 + Integer.min(Integer.min(top, left), diagonal);
        }
 
        // update maximum size found so far
        maxsize.set(Integer.max(maxsize.get(), size));
 
        // return the size of the largest square matrix ending at mat[m][n]
        return size;
    }
 
    public static int findLargestSquareSubmatrix(int[][] mat)
    {
        // base case
        if (mat == null || mat.length == 0) {
            return 0;
        }
 
        // `M × N` matrix
        int M = mat.length;
        int N = mat[0].length;
 
        // `size` stores the size of the largest square submatrix of 1's
        // and is passed by reference using the `AtomicInteger` class
        AtomicInteger maxsize = new AtomicInteger();
 
        findLargestSquare(mat, M - 1, N - 1, maxsize);
        return maxsize.get();
    }
 
    public static void main(String[] args)
    {
        int[][] mat =
                {
                        { 0, 0, 1, 0, 1, 1 },
                        { 0, 1, 1, 1, 0, 0 },
                        { 0, 0, 1, 1, 1, 1 },
                        { 1, 1, 0, 1, 1, 1 },
                        { 1, 1, 1, 1, 1, 1 },
                        { 1, 1, 0, 1, 1, 1 },
                        { 1, 0, 1, 1, 1, 1 },
                        { 1, 1, 1, 0, 1, 1 }
                };
 
        System.out.println("The size of largest square submatrix of 1's is " +
                findLargestSquareSubmatrix(mat));
    }
}





