class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }

        map<char, int> char_cnt;
        int max_len = 1;
        int left = 0, right = 0;
        char_cnt[s[left]]++;
        while (right + 1 < s.size()) {
            right++;
            char_cnt[s[right]]++;
            while (char_cnt[s[right]] > 1) {
                char_cnt[s[left]]--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
