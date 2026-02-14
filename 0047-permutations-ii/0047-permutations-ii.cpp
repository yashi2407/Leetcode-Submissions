class Solution {
public:
    void util(vector<int>& nums,vector<vector<int>>&ans, int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int i = index;i<nums.size();i++){
            if (used.count(nums[i])) continue;
            used.insert(nums[i]);
            swap(nums[i],nums[index]);
            util(nums,ans,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        util(nums,ans,0);
        return ans;
    }
};