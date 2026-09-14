class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size() == 0) {
            return 0;
        }

        int left = 0, right = 0;
        map<char, int> char_cnt;

        int max_f = 0;
        int max_len = 1;
        while (right < s.size()) {
            char_cnt[s[right]]++;
            max_f = max(max_f, char_cnt[s[right]]);

            int replacements_needed = (right - left + 1) - max_f;
            while (replacements_needed > k) {
                char_cnt[s[left]]--;
                left++;
                replacements_needed = (right - left + 1) - max_f;
            }
            max_len = max(max_len, right - left + 1);
            right++;
        }

        return max_len;
    }
};
