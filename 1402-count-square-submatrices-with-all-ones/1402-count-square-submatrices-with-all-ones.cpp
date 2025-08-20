class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>dp= matrix;
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 0;
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                matrix[i][j] == 1 ? dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1 : 0;
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};