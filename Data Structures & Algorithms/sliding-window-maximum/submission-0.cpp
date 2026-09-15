class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;

        int left = 0, right = k - 1;
        for (int i = left; i <= right; i++) {
            pq.push(make_pair(nums[i], i));
        }
        
        vector<int> maximums(nums.size() - k + 1, -1);
        maximums[0] = pq.top().first;

        int idx = 1;
        while (right + 1 < nums.size()) {
            left++;
            while (!pq.empty() && pq.top().second < left) {
                pq.pop();
            }
            right++;
            pq.push(make_pair(nums[right], right));
            maximums[idx] = pq.top().first;
            idx++;
        }
        return maximums;
    }
};
