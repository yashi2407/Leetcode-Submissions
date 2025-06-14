class Solution {
public:
    int getSubsequenceLength(string &s, string &t, int i , int j, vector<vector<int>>&dp){
        // base case
        if(i>=s.size() || j>=t.size()){
            return 0;
        }
        // if current index matches
        // we can pick or not pick
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]= 1+getSubsequenceLength(s,t,i+1,j+1,dp);
        }
        // if not matching
        return dp[i][j]= max(getSubsequenceLength(s,t,i+1,j,dp),getSubsequenceLength(s,t,i,j+1,dp));
    }
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        int subsequenceLength = getSubsequenceLength(s,t,0,0,dp);
        return s.length()-subsequenceLength;
    }
};