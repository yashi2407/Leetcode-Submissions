class Solution {
public:
    /*
        O(n^2) solution
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
    }*/

    //  O(n) solution!
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                min +=1;
                max+=1;
            }
            else if(s[i] == ')'){
                min-=1;
                max-=1;
            }
            else {
                min-=1;
                max+=1;
            }
            if(min<0){
                min = 0;
            }
            if(max<0){
                return false;
            }
        }
        return min == 0? true : false;

    }
};