class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-2;i>=0;i--){
            int prevBiggest = INT_MAX;
            int swapIndex = -1;
            for(int j = i+1;j<nums.size();j++){
                if(nums[j]>nums[i] && nums[j]<prevBiggest){
                    prevBiggest = nums[j];
                    swapIndex = j;
                }
            }
            if(prevBiggest != INT_MAX){
                swap(nums[i],nums[swapIndex]);
                sort(nums.begin()+i +1,nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};