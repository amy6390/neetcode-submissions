class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> idx_stk;
        vector<int> result(temperatures.size(), -1);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!idx_stk.empty() && temperatures[idx_stk.top()] < temperatures[i]) {
                int day_idx = idx_stk.top();
                result[day_idx] = i - day_idx;
                idx_stk.pop();
            }
            idx_stk.push(i);
        }

        for (int i = 0; i < result.size(); i++) {
            if (result[i] == -1) {
                result[i] = 0;
            }
        }

        return result;
    }
};
