class Solution {
    public int climbStairs(int n) {
        int[] dp = new int [n + 1];
        for (int i = 0; i <= n; i++) {
            dp[i] = 0;
        }
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (i - 1 >= 0) dp[i] = dp[i] + dp[i - 1];
            if (i - 2 >= 0) dp[i] = dp[i] + dp[i - 2];
        }
        return dp[n];
    }
}
