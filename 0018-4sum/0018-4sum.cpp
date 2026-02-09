class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int r = 0;r<nums.size();r++){
            if (r > 0 && nums[r] == nums[r - 1]) continue;
            // 3-sum code
            for (int i = r + 1; i < nums.size(); i++) {
                if (i > r + 1 && nums[i] == nums[i - 1]) continue;  // Skip duplicate 'i'

                int j = i + 1;
                int k = nums.size() - 1;

                while (j < k) {
                    long long sum = 1LL*nums[r] + nums[i] + nums[j] + nums[k];

                    if (sum == target) {
                        ans.push_back({nums[r],nums[i], nums[j], nums[k]});
                        j++;
                        k--;

                        // Skip duplicate 'j' and 'k' AFTER pushing triplet
                        while (j < k && nums[j] == nums[j - 1]) j++;
                        while (j < k && nums[k] == nums[k + 1]) k--;
                    }
                    else if (sum < target) {
                        j++;
                    }
                    else {
                        k--;
                    }
                }
            }

        }
        
        return ans;
        
    }
};