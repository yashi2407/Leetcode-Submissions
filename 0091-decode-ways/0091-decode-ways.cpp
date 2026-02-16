class Solution {
public:
    int util(string s, int currentIndex,vector<int>&dp){
        // base condition
        if(currentIndex>=s.size()){
            return 1;
        }
        if(s[currentIndex] == '0'){
            return 0;
        }
        if(dp[currentIndex]!=-1){
            return dp[currentIndex];
        }
        int ans = 0;
        int num = stoi(s.substr(currentIndex, 2));
        if(num>=10 && num<=26){
            // we can choose two index
            ans += util(s,currentIndex+2,dp);
        }
        // we just goto next index
        ans += util(s,currentIndex+1, dp);
        return dp[currentIndex] = ans;

    }
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
        return util(s,0,dp);
    }
};