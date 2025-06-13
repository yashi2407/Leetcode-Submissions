class Solution {
public:
    int util(vector<int>& nums, int k, int index, vector<int>& dp) {
        if (index == nums.size()) return 0;
        if (dp[index] != -1) return dp[index];
        unordered_map<int, int> freq;
        int minCost = INT_MAX;
        int trimmed = 0; // checking the trimmed length

        for (int i = index; i < nums.size(); ++i) {
            int num = nums[i];
            freq[num]++;
            
            // Update trimmed length dynamically
            if (freq[num] == 2) trimmed += 2;      // first time becoming duplicate → +2
            else if (freq[num] > 2) trimmed += 1;  // additional duplicates → +1

            int cost = k + trimmed;
            int total = cost + util(nums, k, i + 1, dp);
            minCost = min(minCost, total);
        }

        return dp[index] = minCost;
    }

    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return util(nums, k, 0, dp);
    }
};
