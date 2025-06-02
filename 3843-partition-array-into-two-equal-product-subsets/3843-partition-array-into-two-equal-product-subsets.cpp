class Solution {
public:
    bool util(vector<int>& nums, long long target, int index,long long product1, long long product2){
        if(product1>target ||product2>target){
            return false;
        }
        if(index>=nums.size()){
            if(product1 == target && product2 == target){
                return true;
            }
            return false;
        }
        // go in first subset and second subset
        return util(nums,target,index+1,product1*nums[index],product2) || util(nums,target,index+1,product1,product2*nums[index]);
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return util(nums,target,0,1,1);
    }
};