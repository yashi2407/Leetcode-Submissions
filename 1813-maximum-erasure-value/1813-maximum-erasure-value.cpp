class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int i=0,j=0;
        unordered_map<int, int>mp;
        int sum = 0;

        // sliding window
        while(j<nums.size()){
            // do calcualtions for j
            sum += nums[j];
            mp[nums[j]]++;

            // distinct elements yet, found one possible solution!
            if(mp[nums[j]]== 1){
                ans = max(ans, sum);
            }
            // elements has been duplicated!
            while(mp[nums[j]]>1){
                sum -= nums[i];
                mp[nums[i]]--;
                i++;
            }
            j++;

        }
        return ans;
    }
};