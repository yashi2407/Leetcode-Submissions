class Solution {
public:
    int util(int n, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int i = 1;
        int ans = 1e9;
        while (i * i <= n) {
            int choice = i * i;
            ans = min(ans, 1 + util(n - choice, dp));
            i++;
        }

        return dp[n] = ans;
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return util(n, dp);
    }
};