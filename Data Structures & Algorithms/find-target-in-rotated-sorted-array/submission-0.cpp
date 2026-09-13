class Solution {
public:
    int search(vector<int>& nums, int target) {
        int rotated_idx = findMinIndex(nums);

        int left = 0, right = rotated_idx - 1;
        left--;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] < target) {
                left = mid;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        if (left != -1 && nums[left] == target) {
            return left;
        } 

        left = rotated_idx;
        right = (int)nums.size() - 1;
        left--;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] < target) {
                left = mid;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        if (left != -1 && nums[left] == target) {
            return left;
        } 
        return -1;
    }

    int findMinIndex(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;

        //binary searching to find index where the array splits
        int minIdx = 0;
        while (left <= right) {
            if (nums[left] < nums[right]) {
                if (nums[left] < nums[minIdx]) {
                    minIdx = left;
                }
                break;
            }
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[minIdx]) {
                minIdx = mid;
            }

            //mid and left are in the same sorted segment -> nums[mid] > nums[left]
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } else { //mid and right are in the same sorted segment
                right = mid - 1;
            }
        }

        return minIdx;
    }
};
