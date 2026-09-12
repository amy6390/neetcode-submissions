class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;

        //binary searching to find index where the array splits
        int minimum = nums[0];
        while (left <= right) {
            if (nums[left] < nums[right]) {
                minimum = min(minimum, nums[left]);
            }
            int mid = left + (right - left) / 2;
            minimum = min(minimum, nums[mid]);

            //mid and left are in the same sorted segment -> nums[mid] > nums[left]
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } else { //mid and right are in the same sorted segment
                right = mid - 1;
            }
        }

        return minimum;
    }
};
