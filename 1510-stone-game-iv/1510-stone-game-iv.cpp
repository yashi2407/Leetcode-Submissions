class Solution {
public:
    vector<int> dp; // -1 = uncomputed, 0 = false, 1 = true

    bool solve(int n) {
        if (n == 0)
            return false;

        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i * i <= n; i++) {
            int nextState = n - i * i;
            if (!solve(nextState)){
                return dp[n] = true;
            }
        }
        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        dp.assign(n + 1, -1);
        return solve(n);
    }
};