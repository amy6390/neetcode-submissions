class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_count = 0;
        int total_prod = 1;
        for(int i: nums) {
            if (i == 0) {
                zero_count++;
            } else {
                total_prod = total_prod * i;
            }
        }

        vector<int> products;
        for(int i = 0; i < nums.size(); i++) {
            if (zero_count > 1) {
                products.push_back(0);
            } else if (zero_count == 1) {
                products.push_back(nums[i] == 0 ? total_prod : 0);
            } else {
                products.push_back(total_prod / nums[i]);
            }
        }
        return products;
    }
};