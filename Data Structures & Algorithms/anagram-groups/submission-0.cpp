class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, string>> sorted_and_original;
        for(string s: strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            sorted_and_original.push_back(make_pair(sorted_s, s));
        }
        sort(sorted_and_original.begin(), sorted_and_original.end());

        vector<vector<string>> grouped;
        vector<string> curr_group;
        int i = 0;
        int N = (int)sorted_and_original.size();
        while (i < N){
            string curr_anagram = sorted_and_original[i].first;
            curr_group.push_back(sorted_and_original[i].second);
            i++;
            
            while (i < N && sorted_and_original[i].first == curr_anagram) {
                curr_group.push_back(sorted_and_original[i].second);
                i++;
            }

            grouped.push_back(curr_group);
            curr_group.clear();
        }
        return grouped;
    }
};
