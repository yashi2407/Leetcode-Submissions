class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& piles, int index, int M) {
        if (index >= piles.size()) {
            return 0;
        }

        if (dp[index][M] != INT_MIN)
            return dp[index][M];

        int ans = INT_MIN;
        int currentScore = 0;

        for (int x = 1; x <= min(2 * M, (int)piles.size() - index); x++) {
            currentScore += piles[index + x - 1];

            ans = max(ans,
                currentScore - solve(piles, index + x, max(x, M)));
        }

        return dp[index][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n + 1, vector<int>(n + 1, INT_MIN));

        int diff = solve(piles, 0, 1);
        int total = accumulate(piles.begin(), piles.end(), 0);

        return (total + diff) / 2;
    }
};