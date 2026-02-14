class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int nextIndex = abs(nums[i])-1;
            if(nums[nextIndex]>0){
                nums[nextIndex] = -nums[nextIndex];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};