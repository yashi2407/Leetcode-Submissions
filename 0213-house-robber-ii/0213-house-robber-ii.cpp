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
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int>dp1(nums.size()+2,-1);
        vector<int>dp2(nums.size()+2,-1);
        vector<int> temp = nums;
        temp.erase(temp.begin()+ nums.size()-1);
        return max(util(nums,1,dp1),util(temp,0,dp2));
        
    }
};