class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0;
        int max_seq_len = 0;
        while (i < nums.size()) {
            int seq_len = 1;
            int j = i + 1;
            int next_elem = nums[i] + 1;
            while (j < nums.size()){
                if (nums[j] == next_elem - 1) {
                    j++;
                }
                else if (nums[j] == next_elem) {
                    seq_len++;
                    next_elem++;
                    j++;
                }
                else{
                    break;
                }
            }
            max_seq_len = max(max_seq_len, seq_len);
            i = j;
        }
        return max_seq_len;
    }
};
