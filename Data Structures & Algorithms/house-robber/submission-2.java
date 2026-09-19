class Solution {
    public int rob(int[] nums) {
        int[] dp = new int[nums.length];
        for (int i = 0; i < dp.length; i++) {
            dp[i] = 0;
        }
        if (dp.length == 0) {
            return 0;
        } else if (dp.length == 1) {
            return nums[0];
        }

        dp[0] = nums[0];
        dp[1] = Math.max(nums[1], dp[0]);
        for (int i = 2; i < dp.length; i++) {
            dp[i] = dp[i - 1]; //do not rob this store
            dp[i] = Math.max(dp[i], nums[i] + dp[i - 2]); //rob this store
        }
        return dp[nums.length - 1];
    }
}
