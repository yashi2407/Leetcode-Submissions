class Solution {
public:
    int countSubarrays(vector<int>& nums, int sum){
        int currentSum = 0;
        int count = 1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]+ currentSum<=sum){
                currentSum = nums[i]+ currentSum;
            }
            else {
                count++;
                currentSum = nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int minElement = *max_element(nums.begin(),nums.end());
        int maxElement = 0;
        int ans = -1;
        for(int i = 0;i<nums.size();i++){
            maxElement += nums[i];
        }
        if (k == 1) return maxElement;
        // if (k == nums.size()) return *max_element(nums.begin(),nums.end());
        while(minElement <= maxElement){
            int mid = (minElement+maxElement)/2;
            int countSubArray = countSubarrays(nums,mid);
            if(countSubArray > k){
                minElement = mid+1;
            } else {
                // move towards min element in case you find an answer!
                ans = mid;
                maxElement = mid-1;
            }

        }
        return ans;
    }
};