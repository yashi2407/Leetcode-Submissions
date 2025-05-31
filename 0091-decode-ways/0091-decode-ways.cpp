class Solution {
public:
    int util(string s, int index,vector<int>&dp){
        if(index>=s.size()){
            return dp[index]= 1;
        }
        if(s[index] == '0') return dp[index] = 0;
        // two choices, take it alone or club with the second if possible
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans = 0;
        int num = stoi(s.substr(index, 2));
        if (num >= 10 && num <= 26) {
            ans += util(s, index + 2,dp);
        }
        ans+=util(s,index+1,dp);
        return dp[index]= ans;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
        return util(s,0,dp);
    }
};