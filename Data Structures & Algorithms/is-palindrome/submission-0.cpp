class Solution {
public:
    bool isPalindrome(string s) {
        string stripped_s = "";
        for(int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                stripped_s = stripped_s + s[i];
            }
            else if(isalpha(s[i])) {
                stripped_s = stripped_s + (char)tolower(s[i]);
            }
        }

        int i = 0;
        int j = (int)stripped_s.size() - 1;

        while(i < j) {
            if (stripped_s[i] != stripped_s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
