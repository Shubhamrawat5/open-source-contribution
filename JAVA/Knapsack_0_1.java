/**
 * Knapsack_0_1
 */
public class Knapsack_0_1 {
    public static void main(String[] args) {
        int[] val = { 10, 20, 80, 100, 90 };
        int[] wt = { 10, 5, 2, 20, 10 };
        int W = 25;
        System.out.println(zeroOneKnapsack(val, wt, W));
    }

    static int zeroOneKnapsack(int[] val, int[] wt, int W) {
        // initialize
        int[][] dp = new int[val.length + 1][W + 1];

        int n = val.length;
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= W; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                if (wt[i - 1] <= j) {
                    dp[i][j] = Math.max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][W];
    }
}
