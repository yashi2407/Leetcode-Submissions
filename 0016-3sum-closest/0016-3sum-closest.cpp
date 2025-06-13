class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];  // initial guess

        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                // Update if this sum is closer to the target
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else {
                    return target;  // exact match
                }
            }
        }

        return closestSum;
    }
};