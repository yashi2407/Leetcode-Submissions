class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int row, int target){
        int low = 0, high = matrix[0].size()-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[row][mid] == target)
                return true;
            if (matrix[row][mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        while (row < m && matrix[row][n - 1] < target) {
            row++;
        }
        if (row == m || (row > 0 && matrix[row][0] > target)) {
            return false;
        }
        //binary search on the row.
        return binarySearch(matrix, row, target);
        
    }
};