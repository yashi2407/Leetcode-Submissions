class Solution {
public:
    int util(vector<int>& nums, int currentIndex, int lastIndex, vector<vector<int>>&dp){
        // base case
        if(currentIndex>=nums.size()){
            return 0;
        }
        if(dp[currentIndex][lastIndex+1]!=-1){
            return dp[currentIndex][lastIndex+1];
        }
        // take the current index
        int take = 0;
        int notTake = 0;
        if(lastIndex == -1 || nums[lastIndex]<nums[currentIndex]){
            take = 1 + util(nums,currentIndex+1, currentIndex,dp);
        }
        notTake = util(nums,currentIndex+1, lastIndex,dp);
        return dp[currentIndex][lastIndex+1]= max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+2,-1));
        return util(nums,0,-1,dp);
    }
};