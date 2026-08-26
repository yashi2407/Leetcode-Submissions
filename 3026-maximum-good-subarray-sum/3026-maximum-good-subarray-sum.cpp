class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long ,long long >mp;
        long long currentSum = 0;
        long long ans = LLONG_MIN;
        currentSum += nums[0];
        mp[nums[0]] = currentSum;
        for(int j=1;j<nums.size();j++){
            // let's assume our subarray ends at j,
            currentSum += nums[j];
            long long  temp1 = k + nums[j];
            long long  temp2 = nums[j] - k;
            if(mp.find(temp1)!= mp.end()){
                ans = max(ans,(currentSum - mp[temp1] + temp1));
            }
            if(mp.find(temp2)!= mp.end()){
                ans = max(ans,(currentSum - mp[temp2] + temp2));
            }
            // push currentSum into nums[j]
            if(mp.find(nums[j]) == mp.end()){
                mp[nums[j]] = currentSum;
            }
            mp[nums[j]] = min(currentSum,mp[nums[j]]);
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};