class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<vector<int>> triplets;
        for(int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = (int) nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                }
                else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                else{
                    if (j != k){
                        triplets.insert({nums[i], nums[j], nums[k]});
                    }
                    j++;
                    k--;
                }
            }
        }
        
        vector<vector<int>> ans_triplets;
        for(auto i: triplets) {
            ans_triplets.push_back(i);
        }
        return ans_triplets;
    }
};
