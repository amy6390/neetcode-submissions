class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_time = 1, max_time = INT_MAX - 1;

        while (min_time < max_time) {
            int mid = min_time + (max_time - min_time) / 2;
            int total_time = calculate_time(piles, mid);

            if (total_time <= h) {
                max_time = mid;
            }
            else {
                min_time = mid + 1;
            }
        }
        return max_time;
    }

    int calculate_time(vector<int>& piles, int k) {
        int total_time = 0;
        for (int pile: piles) {
            if (pile % k == 0) {
                total_time += (pile / k);
            }
            else {
                total_time += ((pile / k) + 1);
            }
        }
        return total_time;
    }
};
