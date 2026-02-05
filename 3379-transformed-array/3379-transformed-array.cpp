class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                result[i] = nums[i];
            }
            else {
                int newIndex = ((i + nums[i]) % n + n) % n;
                result[i] = nums[newIndex];
            }
        }
        return result;
    }
};