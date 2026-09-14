class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> char_freqs(26, 0);
        for (char c: s1) {
            char_freqs[c - 'a']++; 
        }

        int left = 0, right = s1.size() - 1;
        vector<int> curr_char_freqs(26, 0);
        for (int i = left; i <= right; i++) {
            curr_char_freqs[s2[i] - 'a']++;
        }

        while (right < s2.size()) {
            bool found = true;
            for (int i = 0; i < 26; i++) {
                if (curr_char_freqs[i] != char_freqs[i]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
            if (right + 1 >= s2.size()) {
                break;
            }
            right++;
            curr_char_freqs[s2[right] - 'a']++;
            curr_char_freqs[s2[left] - 'a']--;
            left++;
        }
        return false;
    }
};
