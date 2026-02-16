class Solution {
public:
    bool util(string s,vector<string>& wordDict, int currentIndex, vector<int> &dp){
        // base case!
        if(currentIndex>=s.size()){
            return true;
        }
        if (dp[currentIndex] != -1) return dp[currentIndex];
        // from currentIndex, I can try breaking at all the valid positions
        for(int i = currentIndex;i<s.size();i++){
            string temp = s.substr(currentIndex, i-currentIndex+1);
            auto it = find(wordDict.begin(), wordDict.end(), temp);
            if (it != wordDict.end()) {
                if(util(s,wordDict,i+1,dp)){
                    return dp[currentIndex] = true;
                }
            }
        }
        return dp[currentIndex]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return util(s,wordDict,0,dp);
    }
};