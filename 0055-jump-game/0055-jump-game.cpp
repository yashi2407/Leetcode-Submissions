class Solution {
public:
    bool util(vector<int>& nums, int currentIndex,vector<int>&dp){
        if(currentIndex >=nums.size()-1){
            return true;
        }
        if(dp[currentIndex]!= -1){
            return dp[currentIndex];
        }
        int maxJumps = nums[currentIndex];
        for(int i=1;i<=maxJumps;i++){
            if(util(nums,currentIndex+i,dp)){
                return dp[currentIndex] = true;
            }
        }
        return dp[currentIndex] = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return util(nums,0,dp);
    }
};