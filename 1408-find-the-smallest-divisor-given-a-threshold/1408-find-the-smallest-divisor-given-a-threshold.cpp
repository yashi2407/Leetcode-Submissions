class Solution {
public:
    int getThreshold(vector<int>& nums, int divisor){
        int currentThreshold = 0;
        for(int i = 0;i<nums.size();i++){
            currentThreshold = currentThreshold + (nums[i]+divisor-1)/divisor;
        }
        return currentThreshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = -1;
        int low=1,high=*max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid = (low+high)/2;
            int currentThreshold = getThreshold(nums,mid);
            // if we found the divisor within threshold, we need to look for a smaller one
            if(currentThreshold<=threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};