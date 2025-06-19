class Solution {
public:
    int m;
    vector<vector<vector<int>>> dp;

    int util(vector<int>& houses, vector<vector<int>>& cost, int target, int prevColour,
             int index, int neighbours, int n) {
        if (index == m) {
            return (neighbours == target) ? 0 : INT_MAX;
        }

        if (neighbours > target) return INT_MAX;

        if (dp[index][prevColour + 1][neighbours] != -1)
            return dp[index][prevColour + 1][neighbours];

        int ans = INT_MAX;

        if (houses[index] != 0) {
            int newNeighbour = neighbours + (houses[index] != prevColour);
            ans = util(houses, cost, target, houses[index], index + 1, newNeighbour, n);
        } else {
            for (int i = 1; i <= n; i++) {
                int newNeighbour = neighbours + (i != prevColour);
                int sub = util(houses, cost, target, i, index + 1, newNeighbour, n);
                if (sub != INT_MAX) {
                    ans = min(ans, cost[index][i - 1] + sub);
                }
            }
        }

        return dp[index][prevColour + 1][neighbours] = ans;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m_, int n, int target) {
        m = m_;
        dp = vector<vector<vector<int>>>(m + 1, vector<vector<int>>(n + 2, vector<int>(target + 1, -1)));
        int result = util(houses, cost, target, -1, 0, 0, n);
        return result == INT_MAX ? -1 : result;
    }
};
