class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 1;i<nums.size();i++){
            int k = i,j=i-1;
            while(j>=0 && nums[j]>nums[k]){
                swap(nums[j],nums[k]);
                j--; 
                k--;
            }
        }
    }
};