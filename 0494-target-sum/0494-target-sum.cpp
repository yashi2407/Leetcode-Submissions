class Solution {
public:
    int countSubset(vector<int>& nums, int newTarget, int index,vector<vector<int>>&dp){
        if(index>=nums.size()){
            if(newTarget == 0){
                return 1;
            }
            return 0;
        }
        if(dp[index][newTarget]!=-1){
            return dp[index][newTarget];
        }
        // can pick the current index
        int left=0,right=0;
        if(nums[index]<=newTarget){
            left = countSubset(nums,newTarget-nums[index],index+1,dp);
        }

        // don't pick the current index
        right = countSubset(nums,newTarget,index+1,dp);
        return dp[index][newTarget]=left+right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int newTarget = (sum+target)/2;
        if ((sum + target) % 2 != 0 || abs(target) > sum) {
            return 0;
        }
        vector<vector<int>>dp(nums.size()+1,vector<int>(newTarget+1,-1));
        return countSubset(nums,newTarget,0,dp);
    }
};