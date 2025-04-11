class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        // if first element is peak
        if(nums[0]>nums[1]){
            return 0;
        }
        // if last element is peak
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        // perfrom Binary Search on remaining to find peak element
        int low = 1, high = n-2;
        while(low<=high){
            int mid = (low+high)/2;
            // if mid is peak element
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            // is mid in increasing slope, if yes? move to right
            if(nums[mid]<nums[mid+1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};