class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> timemap;

    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& all_vals = timemap[key];

        int left = 0, right = all_vals.size() - 1;
        string ans = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (all_vals[mid].first <= timestamp) {
                left = mid + 1;
                ans = all_vals[mid].second;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
