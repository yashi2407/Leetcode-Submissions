class Solution {
public:
    int dp[305][305];  // memo table

    int util(vector<int>& nums, int left, int right) {
        if (left > right) return 0;
        if (dp[left][right] != -1) return dp[left][right];

        int maxCoins = 0;

        for (int i = left; i <= right; ++i) {
            int gain = nums[left - 1] * nums[i] * nums[right + 1];
            int remaining = util(nums, left, i - 1) + util(nums, i + 1, right);
            maxCoins = max(maxCoins, gain + remaining);
        }

        return dp[left][right] = maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        // Step 1: Pad nums with 1s at both ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // Step 2: Initialize DP table
        memset(dp, -1, sizeof(dp));

        // Step 3: Call util from 1 to n (skip the padding)
        return util(nums, 1, nums.size() - 2);
    }
};
