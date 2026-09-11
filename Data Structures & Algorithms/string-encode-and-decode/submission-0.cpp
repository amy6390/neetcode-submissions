class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (string s: strs) {
            int l = s.size();
            string encoded_s = to_string(l) + "#" + s;
            encoded = encoded + encoded_s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        int i = 0;
        while (i < s.size()) {
            int length = 0;
            while(s[i] != '#') {
                length = length * 10 + (s[i] - '0');
                i++;
            }
            i++; //to move past # character
            string str = s.substr(i, length);
            decoded_strs.push_back(str);
            i += length;
        }
        return decoded_strs;
    }
};
