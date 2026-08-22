class Solution {
public:
    int util(vector<int>& nums, int currentIndex,vector<int>&dp){
        if(currentIndex >=nums.size()-1){
            return 0;
        }
        if(dp[currentIndex]!= -1){
            return dp[currentIndex];
        }
        int maxJumps = nums[currentIndex];
        int ans = 1e9;
        for(int i=1;i<=maxJumps;i++){
            ans = min(ans, 1+ util(nums,currentIndex+i,dp));
            
        }
        return dp[currentIndex] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return util(nums,0,dp);
    }
};