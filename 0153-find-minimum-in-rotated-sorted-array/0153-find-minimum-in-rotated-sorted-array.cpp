class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high = nums.size()-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            // check if left sorted
            if (nums[low] <= nums[mid]) {
                // take min of left sorted half and then remove it
                ans = min(ans,nums[low]);
                low = mid+1;
            }
            // Right side is sorted
            else {
                // take min of right sorted half and then remove it
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
        }
        return ans;
        
    }
};