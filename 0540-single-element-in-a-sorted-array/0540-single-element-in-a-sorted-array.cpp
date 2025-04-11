class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }
        // binary search for remaining search space
        int low = 1, high = n-2;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if((mid%2==0 && nums[mid-1]==nums[mid]) || mid%2==1 && nums[mid]==nums[mid+1]){
                // move to left half
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};