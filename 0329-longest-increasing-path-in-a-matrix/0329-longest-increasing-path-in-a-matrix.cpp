class Solution {
public:
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>&dp,int row, int col,int m,int n){
        if(dp[row][col]!=-1){
            return dp[row][col];
        }

        int maxPath = 1;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for (int dir = 0; dir < 4; ++dir) {
            int newRow = row + dx[dir];
            int newCol = col + dy[dir];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                matrix[newRow][newCol] > matrix[row][col]) {
                maxPath = max(maxPath, 1 + dfs(matrix, dp, newRow, newCol,m,n));
            }
        }
        return dp[row][col]= maxPath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                ans = max(ans,dfs(matrix,dp,i,j,m,n));
            }
        }
        return ans;
    }
};