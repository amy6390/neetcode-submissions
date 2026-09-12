class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_l = 0, row_r = (int)matrix.size() - 1;
        row_l--;

        while (row_l < row_r) {
            int mid = row_l + (row_r - row_l + 1) / 2;

            if (matrix[mid][0] < target) {
                row_l = mid;
            }
            else if (matrix[mid][0] > target) {
                row_r = mid - 1;
            }
            else {
                return true;
            }
        }
        if (row_l == -1) {
            return false;
        }

        int col_l = 0, col_r = (int)matrix[row_l].size() - 1;
        while (col_l < col_r) {
            int mid = col_l + (col_r - col_l + 1) / 2;
            if (matrix[row_l][mid] < target) {
                col_l = mid;
            }
            else if (matrix[row_l][mid] > target) {
                col_r = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
