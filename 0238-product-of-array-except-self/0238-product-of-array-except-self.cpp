class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixSum(nums.size());
        prefixSum[0]=1;
        for(int i=1;i<nums.size();i++){
            prefixSum[i] = prefixSum[i-1]*nums[i-1];
        }
        vector<int> suffixSum(nums.size());
        suffixSum[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;i--){
            suffixSum[i] = suffixSum[i+1]*nums[i+1];
        }
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i] = prefixSum[i]*suffixSum[i];
        }
        return ans;
    }
};