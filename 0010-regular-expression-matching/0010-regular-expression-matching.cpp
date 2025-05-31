class Solution {
public:
    bool util(string s, string p, int i , int j, vector<vector<int>>&dp){
       // base case
       if(i == s.length() && j==p.length()){
        return dp[i][j]= true;
       }
       // if pattern gets finished but string is not
       if(j==p.length()){
        return dp[i][j]=false;
       }
       if(dp[i][j]!=-1) {
        return dp[i][j];
       }
       bool currentMatch  = (i < s.length()) && (s[i] == p[j] || p[j] == '.');

       if(j+1<p.length() && p[j+1] == '*'){
        // Don't match the character of s[i]
        bool zeroMatch = util(s,p,i,j+2,dp);

        // if the current character match, see if there are more of the same element
        bool oneOrMoreMatch = currentMatch && util(s,p,i+1,j,dp);
        return dp[i][j]= zeroMatch || oneOrMoreMatch;
       }
       if(currentMatch) {
            return dp[i][j]= util(s,p,i+1,j+1,dp);
       }
       return dp[i][j]= false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,-1));
        return util(s,p,0,0,dp);
    }
};