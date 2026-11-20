class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& piles, int index) {
        if (index >= piles.size()) {
            return 0;
        }
        if (dp[index] != INT_MIN)
            return dp[index];

        int ans = INT_MIN;
        int currentScore = 0;
        for (int x = 1; x <= min(3, (int)piles.size() - index); x++) {
            currentScore += piles[index + x - 1];
            ans = max(ans, currentScore - solve(piles, index + x));
        }

        return dp[index] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n, INT_MIN);
        int diff = solve(stoneValue, 0);
        if (diff == 0)
            return "Tie";
        else if (diff > 0)
            return "Alice";
        return "Bob";
    }
};