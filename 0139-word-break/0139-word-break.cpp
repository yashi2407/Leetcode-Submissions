class Solution {
public:
    bool util(string s, map<string,int>&mp,int indexi,vector<int>&dp){
        if(indexi>=s.size()){
            return true;
        }
        if(dp[indexi]!=-1){
            return dp[indexi];
        }
        for(int i = indexi;i<s.size()+1;i++){
            string s1 = s.substr(indexi, i - indexi);
            if(mp.find(s1)!= mp.end()){
                if(util(s,mp,i,dp)){
                    return dp[indexi]= true;
                } 
            }
        }
        return dp[indexi]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int>mp;
        for(int i =0;i<wordDict.size();i++){
            mp[wordDict[i]]++;
        }

        vector<int>dp(s.size()+1,-1);
        return util(s,mp,0,dp);
    }
};