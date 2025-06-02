class Solution {
public:
    int util(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
        if (row >= grid.size() || col >= grid[0].size() || grid[row][col] == 1) return 0;

        if (row == grid.size() - 1 && col == grid[0].size() - 1) return 1;

        if (dp[row][col] != -1) return dp[row][col];

        int right = util(grid, row, col + 1, dp);
        int down = util(grid, row + 1, col, dp);

        return dp[row][col] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return util(obstacleGrid, 0, 0, dp);
    }
};
