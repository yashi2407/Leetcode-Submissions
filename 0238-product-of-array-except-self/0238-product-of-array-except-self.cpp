class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct(nums.size(),1);
        leftProduct[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            leftProduct[i] = leftProduct[i-1] * nums[i];
        }
        // get right product!
        vector<int> rightProduct(nums.size(),1);
        rightProduct[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size()-2;i>=0;i--){
            rightProduct[i] = rightProduct[i+1] * nums[i];
        }
        vector<int>ans(nums.size(),0);
        ans[0] = rightProduct[1];
        ans[nums.size()-1] = leftProduct[nums.size()-2];
        for(int i =1;i<nums.size()-1;i++){
            ans[i] = leftProduct[i-1] * rightProduct[i+1];
        }
        return ans;
    }
};