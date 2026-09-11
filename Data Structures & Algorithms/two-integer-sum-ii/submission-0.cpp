class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        sort(numbers.begin(), numbers.end());

        int i = 0;
        int j = (int)numbers.size() - 1;
        vector<int> solution;

        while (i < numbers.size() && j >= 0 && i != j) {
            if (numbers[i] + numbers[j] < target) {
                i++;
            }
            else if (numbers[i] + numbers[j] > target) {
                j--;
            }
            else {
                solution.push_back(i + 1);
                solution.push_back(j + 1);
                return solution;
            }
        }
        return solution;
    }
};
