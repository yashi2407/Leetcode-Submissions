class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = INT_MIN;
        // strictly increasing
        int i = 0;
        while(i<nums.size()){
            int start = i;
            while(i<nums.size()-1 && nums[i]<nums[i+1]){
                i++;
            }
            ans = max(ans,i-start+1);
            i++;
        }
        i = 0;
        // strictly decreasing
        while(i<nums.size()){
            int start = i;
            while(i<nums.size()-1 && nums[i]>nums[i+1]){
                i++;
            }
            ans = max(ans,i-start+1);
            i++;
        }
        return ans;
    }
};