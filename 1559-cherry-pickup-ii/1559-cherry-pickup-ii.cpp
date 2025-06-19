class Solution {
public:
    int dp[71][71][71]; // grid size max is 70

    int util(vector<vector<int>>& grid, int row, int col1, int col2) {
        int rows = grid.size(), cols = grid[0].size();

        // Out of bounds
        if (col1 < 0 || col2 < 0 || col1 >= cols || col2 >= cols)
            return INT_MIN;

        // Check memoized result
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        // Last row base case
        if (row == rows - 1) {
            if (col1 == col2)
                return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }

        int ans = 0;
        if (col1 == col2)
            ans += grid[row][col1];
        else
            ans += grid[row][col1] + grid[row][col2];

        int maxFuture = INT_MIN;
        vector<int> delCol = {-1, 0, 1};

        for (int d1 : delCol) {
            for (int d2 : delCol) {
                int next = util(grid, row + 1, col1 + d1, col2 + d2);
                if (next != INT_MIN) {
                    maxFuture = max(maxFuture, next);
                }
            }
        }

        return dp[row][col1][col2] = ans + maxFuture;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return util(grid, 0, 0, grid[0].size() - 1);
    }
};
