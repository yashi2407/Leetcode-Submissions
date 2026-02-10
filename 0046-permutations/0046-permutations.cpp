class Solution {
public:
    void util(vector<int>& nums,vector<vector<int>> &ans, int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            util(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        util(nums,ans,0);
        return ans;
    }
};