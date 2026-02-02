class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        int ans = nums[0];

        for (int i = 1;i<nums.size();i++) {
            if (nums[i] < firstMin) {
                secondMin = firstMin;
                firstMin = nums[i];
            }
            else if (nums[i] < secondMin) {
                secondMin = nums[i];
            }
        }
        return ans+(int)firstMin+(int)secondMin;
    }
};