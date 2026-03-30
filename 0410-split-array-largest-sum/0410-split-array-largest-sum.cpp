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
        for(int i=0;i<nums.size();i++){
            maxElement += nums[i];
        }
        int ans = 0;
        while(minElement<=maxElement){
            int sum = (minElement+ maxElement)/2;
            if(countSubarrays(nums,sum)>k){
                minElement = sum + 1;
            }
            else {
                ans = sum;
                maxElement = sum - 1;
            }
        }
        return ans;
    }
};