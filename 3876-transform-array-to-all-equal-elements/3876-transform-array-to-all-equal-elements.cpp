class Solution {
public:
    bool canMake(vector<int>nums, int target,int k){
        int count = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] !=target){
                // flip it
                nums[i] *= -1;
                nums[i + 1] *= -1;
                count++;
                if(count>k){
                    return false;
                }

            }
        }
        return nums[nums.size() - 1] == target;
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        return canMake(nums,1,k) || canMake(nums,-1,k);
    }
};