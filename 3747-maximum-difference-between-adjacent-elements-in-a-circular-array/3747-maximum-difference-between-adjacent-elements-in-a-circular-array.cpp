class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int ans =INT_MIN;
        ans = abs(nums[0]-nums[nums.size()-1]);// last and first element
        for(int i=1;i<nums.size();i++){
            ans=max(ans,abs(nums[i]-nums[i-1]));
        }
        return ans;

    }
};