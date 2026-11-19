class Solution {
public:
    vector<long long> dp;

    long long solve(int index, vector<int>& nums) {
        if (index >= nums.size()) {
            return 0;
        }

        if (dp[index] != LLONG_MIN)
            return dp[index];

        long long result = LLONG_MIN;
        long long currentSum = 0;

        for (int x = 1; x <= 2 && index + x <= nums.size(); x++) {
            currentSum += nums[index + x - 1];

            if (currentSum % 3 == 0) {
                // Opponent will play
                result = max(result,
                    currentSum - solve(index + x, nums));
            } else {
                // Same player will play
                result = max(result,
                    currentSum + solve(index + x, nums));
            }
        }

        return dp[index] = result;
    }

    long long maxDifference(vector<int>& nums) {
        dp.assign(nums.size(), LLONG_MIN);
        return solve(0, nums);
    }
};