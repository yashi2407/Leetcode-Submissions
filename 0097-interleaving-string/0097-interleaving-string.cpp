class Solution {
public:
    bool util(string& s1, string& s2, string& s3, int i1, int i2,vector<vector<int>>&dp ) {
        if (i1 == s1.size() && i2 == s2.size()) return true;

        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }

        bool take1 = false, take2 = false;
        int i3=i1+i2;
        if (i1 < s1.size() && s1[i1] == s3[i3])
            take1 = util(s1, s2, s3, i1 + 1, i2,dp);
        if (i2 < s2.size() && s2[i2] == s3[i3])
            take2 = util(s1, s2, s3, i1, i2 + 1,dp);

        return dp[i1][i2]= take1 || take2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        if (s1.size() + s2.size() != s3.size()) return false;
        return util(s1,s2,s3,0,0,dp);
    }
};