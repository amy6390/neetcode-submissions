class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> suffix_max(n, 0);
        suffix_max[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_max[i] = max(suffix_max[i + 1], prices[i]);
        }

        int max_profit = 0;
        for (int i = 0; i < n - 1; i++) {
            max_profit = max(max_profit, suffix_max[i + 1] - prices[i]);
        }
        return max_profit;
    }
};
