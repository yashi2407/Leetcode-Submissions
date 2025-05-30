class Solution {
public:
    void util(vector<int>& nums,vector<vector<int>> &ans, vector<int>&current,int index){
        ans.push_back(current);
        for(int i = index;i<nums.size();i++){
            if(i!=index && nums[i] == nums[i - 1]){
                continue;
            }
            current.push_back(nums[i]);
            util(nums,ans,current,i+1);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int>current;
        util(nums,ans,current,0);;
        return ans;
    }
};