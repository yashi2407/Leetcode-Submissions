class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int leftMultiply = 1;
        int rightMultiply = 1;
        int ans = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            leftMultiply = leftMultiply * nums[i];
            ans = max(ans,leftMultiply);
            if(leftMultiply == 0){
                leftMultiply = 1;
            }
            rightMultiply = rightMultiply * nums[nums.size()-i-1];
            ans = max(ans,rightMultiply);
            if(rightMultiply == 0){
                rightMultiply = 1;
            }
        }
        return ans;
    }
};