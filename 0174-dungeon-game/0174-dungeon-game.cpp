class Solution {
public:
    int util(vector<vector<int>>& dungeon, int row, int col,vector<vector<int>>&dp){
        if (row == dungeon.size() - 1 && col == dungeon[0].size() - 1) {
            return dp[row][col] = max(1, 1 - dungeon[row][col]);
        }
        if(row>=dungeon.size() || col>=dungeon[0].size()){
            return INT_MAX;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int down = util(dungeon,row+1,col,dp);   
        int right = util(dungeon,row,col+1,dp); 
        int minNext = min(down, right);
        return dp[row][col]= max(1,minNext-dungeon[row][col]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return util(dungeon,0,0,dp);
    }
};