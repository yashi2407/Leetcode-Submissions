class Solution {
public:
    bool util(string &s, int index, int count, vector<vector<int>> &dp){
        if(count<0){
            return false;
        }
        if(index>=s.size()){
            if(count == 0){
                return true;
            }
            return false;
        }
        if(dp[index][count]!=-1){
            return dp[index][count];
        }
        bool ans;
        // option to make * as ( or "" or )
        if(s[index]== '*'){
            ans =  util(s,index+1,count+1,dp) || util(s,index+1,count,dp) || util(s,index+1,count-1,dp);
        }
        else if(s[index] == '('){
            ans = util(s,index+1,count+1,dp);
        }
        else {
            ans =  util(s,index+1,count-1,dp);
        }
        return dp[index][count] = ans;
    }
    bool checkValidString(string s) {
        int index = 0;
        int count = 0;
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size() + 1, -1));
        return util(s,index,count,dp);
    }
};