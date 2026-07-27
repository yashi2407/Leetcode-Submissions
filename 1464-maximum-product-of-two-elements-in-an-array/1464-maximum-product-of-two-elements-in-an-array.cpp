class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        for(int i=0;i<nums.size();i++){
            // update the first max and second max!
            if(nums[i]>=firstMax){
                secondMax = firstMax;
                firstMax = nums[i];
            }
            // update second max
            else if(nums[i]<firstMax && nums[i]>=secondMax){
                secondMax = nums[i];
            }
        }
        return (firstMax-1)*(secondMax-1);
    }
};