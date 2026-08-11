class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int currentSum = 0;
        int ans = INT_MAX;
        while(j<nums.size()){
            currentSum += nums[j];
            while(currentSum>=target){
                ans = min(ans, j-i+1);
                currentSum = currentSum - nums[i];
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};