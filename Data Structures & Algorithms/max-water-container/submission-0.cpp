class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_water = 0;
        int i = 0;
        int j = (int)heights.size() - 1;
        while (i < j) {
            int water_stored = min(heights[i], heights[j]) * (j - i);
            max_water = max(max_water, water_stored);
            
            if (heights[i] < heights[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return max_water;
    }
};
