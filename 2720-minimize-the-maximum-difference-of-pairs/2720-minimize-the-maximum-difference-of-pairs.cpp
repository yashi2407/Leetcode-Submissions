class Solution {
public:
    bool canForm(vector<int>& nums, int p, int maxDiff){
        int count = 0;
        int i = 0;
        while (i < nums.size() - 1) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                count++;
                i += 2; // skip both indices used in the pair
            } else {
                i++; // try next index
            }
        }
        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = abs(nums[0]-nums[nums.size()-1]);
        while(low<high){
            int mid = (low+high)/2;
            if(canForm(nums,p,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};