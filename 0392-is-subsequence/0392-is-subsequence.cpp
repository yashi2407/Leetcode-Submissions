class Solution {
public:
    bool util(string s, string t, int i, int j, vector<vector<int>>&dp){
        // base case
        if(i>= s.size()){
            return true;
        }
        if (j >= t.size()) return false;
        bool take = false;
        bool notTake = false;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            take = util(s,t,i+1,j+1,dp);
        }
        notTake = util(s,t,i,j+1,dp);
        return dp[i][j] = take || notTake;
    }
    bool isSubsequence(string s, string t) {
        int i = 0; int j = 0;
        vector<vector<int>>dp(s.size()+1, vector<int>(t.size()+1,-1));
        return util(s,t,i,j,dp);
    }
};