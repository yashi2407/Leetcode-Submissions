class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // we will use the given vector itself. 
        //Let's sayt hat nums[x-1] should have value x
        //ie nums[2] = 3.
        int n = nums.size();
        for(int i =0;i<n;i++){
            // x == nums[i];
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){
                swap(nums[nums[i]-1],nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};