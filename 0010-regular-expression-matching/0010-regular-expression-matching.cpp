class Solution {
public:
    bool util(string s, string p, int i, int j, vector<vector<int>> &dp){
        if (i == s.length() && j == p.length()) return dp[i][j]= true;

        // If pattern is finished but string is not → fail
        if (j == p.length()) return dp[i][j]= false;

        if (dp[i][j] != -1) return dp[i][j];

        if (j + 1 < p.length() && p[j + 1] == '*') {
            // Case 1: Zero matching, I won't be matching any character at j+1 so. move to j+2
            // eg- aaab and a* b so I am basically saying that a* for me ''.
            if (util(s, p, i, j + 2, dp)) return dp[i][j]= true;

            // Case 2: One or more occurrences s = "aaab",  p = "a*b"
            if (i < s.length() && (s[i] == p[j] || p[j] == '.')) {
                if (util(s, p, i + 1, j, dp)) return dp[i][j] = true;
            }

            return dp[i][j]= false; // if neither worked
        }
        if (i < s.length() && (p[j] == s[i] || p[j] == '.')) {
            return dp[i][j]= util(s, p, i + 1, j + 1, dp);
        }
        return dp[i][j]= false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return util(s,p,0,0,dp);
    }
};