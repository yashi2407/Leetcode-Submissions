class Solution {
public:
    vector<array<long long, 4>> dp;

    long long solve(vector<int>& nums, int i, int trend) {
        int n = nums.size();

        // Base case
        if (i == n) {
            return (trend == 3) ? 0 : LLONG_MIN / 4;
        }

        // Memo check (LLONG_MIN means uncomputed)
        if (dp[i][trend] != LLONG_MIN)
            return dp[i][trend];

        long long take = LLONG_MIN / 4;
        long long skip = LLONG_MIN / 4;

        // Skip allowed only before starting
        if (trend == 0) {
            skip = solve(nums, i + 1, 0);
        }

        // End allowed if trend == 3
        if (trend == 3) {
            take = nums[i];
        }

        // Transition if next exists
        if (i + 1 < n) {
            int current = nums[i];
            int next = nums[i + 1];

            if (trend == 0 && next > current) {
                take = max(take, (long long)current + solve(nums, i + 1, 1));
            }
            else if (trend == 1) {
                if (next > current) {
                    take = max(take, (long long)current + solve(nums, i + 1, 1));
                }
                else if (next < current) {
                    take = max(take, (long long)current + solve(nums, i + 1, 2));
                }
            }
            else if (trend == 2) {
                if (next < current) {
                    take = max(take, (long long)current + solve(nums, i + 1, 2));
                }
                else if (next > current) {
                    take = max(take, (long long)current + solve(nums, i + 1, 3));
                }
            }
            else if (trend == 3) {
                if (next > current) {
                    take = max(take, (long long)current + solve(nums, i + 1, 3));
                }
            }
        }

        // Store answer
        return dp[i][trend] = max(take, skip);
    }

    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();

        // Initialize dp with LLONG_MIN meaning "uncomputed"
        dp.assign(n, {LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN});

        return solve(nums, 0, 0);
    }
};
