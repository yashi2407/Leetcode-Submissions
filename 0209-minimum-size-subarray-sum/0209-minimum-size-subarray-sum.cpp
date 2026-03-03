class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i = 0; int j = 0;
        int currentSum = 0;
        while(j<nums.size()){
            // do the calculations for j
            currentSum += nums[j];
            while(currentSum >= target){
                ans = min(ans, j-i+1);
                currentSum -= nums[i];
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};