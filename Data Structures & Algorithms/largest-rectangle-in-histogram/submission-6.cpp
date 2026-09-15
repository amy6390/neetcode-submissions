class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stk; //{heights[i], i}

        int N = heights.size();
        vector<int> leftmost(N, -1);
        vector<int> rightmost(N, N);

        for (int i = N - 1; i >= 0; i--) {
            int h = heights[i];
            while (!stk.empty() && stk.top().first >= h) {
                stk.pop();
            }
            if (!stk.empty()) {
                rightmost[i] = stk.top().second;
            }
            stk.push(make_pair(h, i));
        }

        while (!stk.empty()) stk.pop();
        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            while (!stk.empty() && stk.top().first >= h) {
                stk.pop();
            }
            if (!stk.empty()) {
                leftmost[i] = stk.top().second;
            }
            stk.push(make_pair(h, i));
        }

        int max_rect = 0;
        for (int i = 0; i < N; i++) {
            int r = rightmost[i] - 1, l = leftmost[i] + 1;
            int width = r - l + 1;
            max_rect = max(max_rect, width * heights[i]);
        }
        return max_rect;
    }
};
