class Solution {
public:
    bool subset(vector<int>& nums, int n, int sum, vector<vector<int>> &dp){
        if(sum==0){
            return true;
        }
        if(n==0){
            return false;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(nums[n-1]>sum){
            //won't include
            return dp[n][sum]= subset(nums,n-1,sum,dp);
        }
        return dp[n][sum]=(subset(nums,n-1,sum-nums[n-1],dp) || subset(nums,n-1, sum,dp));
    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum/2+1,-1));
        return subset(nums,nums.size(),sum/2 ,dp);
    }
};