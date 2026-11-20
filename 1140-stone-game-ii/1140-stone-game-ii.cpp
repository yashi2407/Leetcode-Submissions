class Solution {
public:
    int dp[2][101][101];

    int solveForAlice(vector<int>& piles, int index, int M, int player) {
        if (index >= piles.size())
            return 0;

        if (dp[player][index][M] != -1)
            return dp[player][index][M];

        int ans = (player == 1) ? INT_MIN : INT_MAX;
        int currentScore = 0;

        for (int x = 1; x <= min(2 * M, (int)piles.size() - index); x++) {
            currentScore += piles[index + x - 1];

            if (player == 1) {
                ans = max(ans,
                    currentScore + solveForAlice(piles, index + x, max(x, M), 0));
            }
            else {
                ans = min(ans,
                    solveForAlice(piles, index + x, max(x, M), 1));
            }
        }

        return dp[player][index][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solveForAlice(piles, 0, 1, 1);
    }
};