class Solution {
public:
    bool canForm(int minDiff, int p, vector<int>& nums){
        int count = 0;
        for(int i=0;i<nums.size()-1;){
            if(nums[i+1]-nums[i]<=minDiff){
                count++;
                i = i+2;
            }
            else{
                i=i+1;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        if(nums.size() == 1){
            return 0;
        }
        int low = 0;
        int high = nums[nums.size()-1] - nums[0];
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if(canForm(mid,p,nums)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};