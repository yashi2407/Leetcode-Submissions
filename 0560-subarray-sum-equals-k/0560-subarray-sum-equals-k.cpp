class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // sum and count
        unordered_map<int,int>mp;
        int currentSum = 0;
        int count = 0;
        mp[0] = 1;
        for(int j=0;j<nums.size();j++){
            int sumI = currentSum + nums[j] - k;
            if(mp.contains(sumI)){
                count+= mp[sumI];
            }
            currentSum+= nums[j];
            mp[currentSum]++;
        }
        return count;
    }
};