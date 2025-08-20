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
        int n = (int)satisfaction.size();
        // dishIndex can go up to n, so allocate n+2 to be safe
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, INT_MIN));
        return util(satisfaction, 0, 1, dp);
    }
};
