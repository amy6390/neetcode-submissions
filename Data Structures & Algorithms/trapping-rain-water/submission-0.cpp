class Solution {
public:
    int trap(vector<int>& height) {
        int N = (int)height.size();

        vector<int> prefix_max(N, 0);
        prefix_max[0] = height[0];
        for(int i = 1; i < N; i++) {
            prefix_max[i] = max(prefix_max[i-1], height[i]);
        }
        vector<int> suffix_max(N, 0);
        suffix_max[N - 1] = height[N - 1];
        for(int i = N - 2; i >= 0; i--) {
            suffix_max[i] = max(suffix_max[i+1], height[i]);
        }

        int water_trapped = 0;
        for (int i = 0; i < N; i++) {
            int trapped_here = max(min(prefix_max[i], suffix_max[i]) - height[i], 0);
            water_trapped += trapped_here;
        }
        return water_trapped;
    }
};
