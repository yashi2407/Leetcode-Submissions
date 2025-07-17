class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>>dp(k,vector<int>(nums.size()+1,1));
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<=i-1;j++){
                int mod = (nums[j] + nums[i]) % k;
                dp[mod][i] = max(dp[mod][i], dp[mod][j]+1);
                ans = max(ans,dp[mod][i]);
            }
        }
        return ans;
    }
};