class Solution {
public:
    int util(vector<int>& satisfaction, int i, int dishIndex, vector<vector<int>>& dp){
        if (i >= (int)satisfaction.size()) return 0;

        if (dp[i][dishIndex] != INT_MIN) return dp[i][dishIndex];

        long long pick = 1LL * satisfaction[i] * dishIndex
                       + util(satisfaction, i + 1, dishIndex + 1, dp);
        long long notPick = util(satisfaction, i + 1, dishIndex, dp);

        return dp[i][dishIndex] = (int)max(pick, notPick);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        // int n = (int)satisfaction.size();
        // // // dishIndex can go up to n, so allocate n+2 to be safe
        // vector<vector<int>> dp(n + 1, vector<int>(n + 2, INT_MIN));
        // return util(satisfaction, 0, 1, dp);

        int n = (int)satisfaction.size();

        // dp[i][dishIndex] = best from i..n-1 when next picked dish has index = dishIndex
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 2, 0));

        // reverse the recursion order:
        // i goes from n-1 down to 0
        // dishIndex goes from n down to 1
        for (int i = n - 1; i >= 0; --i) {
            for (int dishIndex = n; dishIndex >= 1; --dishIndex) {
                long long pick    = 1LL * satisfaction[i] * dishIndex + dp[i + 1][dishIndex + 1];
                long long notPick = dp[i + 1][dishIndex];
                dp[i][dishIndex]  = max(pick, notPick);
            }
        }
        return (int)dp[0][1];
    }
};
