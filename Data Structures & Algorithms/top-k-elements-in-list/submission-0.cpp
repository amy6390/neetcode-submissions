class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int N = (int)nums.size();
        sort(nums.begin(), nums.end());

        vector<pair<int, int>> cnts;
        int i = 0;
        while (i < N) {
            int j = i + 1;
            int cnt = 1;
            while(j < N && nums[i] == nums[j]){
                cnt++;
                j++;
            }
            cnts.push_back(make_pair(cnt, nums[i]));
            i = j;
        }
        sort(cnts.begin(), cnts.end());

        vector<int> top_k;
        int idx = cnts.size() - 1;
        for (int i = 0; i < k; i++) {
            top_k.push_back(cnts[idx].second);
            idx--;
        }
        return top_k;
    }
};
