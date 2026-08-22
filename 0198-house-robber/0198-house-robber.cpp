class Solution {
public: 
    int util(vector<int>& nums, int currentIndex,vector<int>&dp){
        if(currentIndex>=nums.size()){
            return 0;
        }
        // at this index, either i loot it or not
        if(dp[currentIndex] !=-1){
            return dp[currentIndex];
        }
        int take = nums[currentIndex] + util(nums,currentIndex+2,dp);;
        int notTake = util(nums,currentIndex+1,dp);;
        return dp[currentIndex] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+2,-1);
        return util(nums,0,dp);
    }
};