class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {

            // 1) Go Right
            for (int j = left; j <= right; j++)
                ans.push_back(matrix[top][j]);
            top++;

            // 2) Go Down
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            // 3) Go Left
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    ans.push_back(matrix[bottom][j]);
                bottom--;
            }

            // 4) Go Up
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};
