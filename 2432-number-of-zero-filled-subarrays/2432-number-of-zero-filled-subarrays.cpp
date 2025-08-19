class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long run=0, ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                run++;
                ans+=run;
            }
            else{
                run=0;
            }
        }
        return ans;
    }
};