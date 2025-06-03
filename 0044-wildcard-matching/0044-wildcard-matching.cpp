class Solution {
public:
    bool util(string s, string p, int i,int j,vector<vector<int>>&dp){
        if (i > s.size() || j > p.size()) return false;
        if(i == s.size() && j == p.size()){
            return true;
        }
        if(j==p.size()){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if((s[i]==p[j] || p[j]=='?')){
            return dp[i][j]= util(s,p,i+1,j+1,dp);
        }
        if(p[j]=='*'){
            // can verify zero or multiple
            return dp[i][j]=util(s,p,i,j+1,dp) || util(s,p,i+1,j,dp);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return util(s,p,0,0,dp);
    }
};