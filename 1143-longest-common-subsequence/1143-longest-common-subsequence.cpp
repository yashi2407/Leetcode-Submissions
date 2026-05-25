class Solution {
public:

    int util(string &text1, string &text2, int index1, int index2, vector<vector<int>> &dp) {
        // base case
        if(index1 < 0 || index2 < 0) {
            return 0;
        }

        if(dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        // match
        if(text1[index1] == text2[index2]) {
            return dp[index1][index2] = 1 + util(text1, text2, index1 - 1, index2 - 1, dp);
        }
        return dp[index1][index2] =
            max(util(text1, text2, index1 - 1, index2, dp), util(text1, text2, index1, index2 - 1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return util(text1, text2, m - 1, n - 1, dp);
    }
};