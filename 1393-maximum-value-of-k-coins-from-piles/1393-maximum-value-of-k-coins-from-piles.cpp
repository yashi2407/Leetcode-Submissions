class Solution {
public:
    int util(vector<vector<int>>& piles, int k, int i,vector<vector<int>>&dp){
        // Base condition
        if(k==0 || i==piles.size()){
            return 0;
        }
        if(dp[k][i]!=-1){
            return dp[k][i];
        }
        // don't take anything from this pile
        int maxVal = util(piles,k,i+1,dp);
        int ans=0;
        //use this pile
        int sum = 0;
        // take j coins from the current pile
        for (int j = 0; j < piles[i].size() && j < k; j++) {
            sum += piles[i][j];
            maxVal = max(maxVal, sum + util(piles, k - j - 1, i + 1,dp));
        }

        return dp[k][i]=maxVal;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>>dp(k+1,vector<int>(piles.size()+1,-1));
        return util(piles,k,0,dp);
    }
};