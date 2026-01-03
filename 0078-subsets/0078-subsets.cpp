class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &ans, int currentIndex, vector<int>currentSubset){
        if(currentIndex>=nums.size()){
            ans.push_back(currentSubset);
            return;
        }
        // don't add the current index and just move onto the next one
        solve(nums,ans,currentIndex+1,currentSubset);
        // add it to current subset and the move onto the next one!
        currentSubset.push_back(nums[currentIndex]);
        solve(nums,ans,currentIndex+1,currentSubset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>currentSubset;
        solve(nums,ans,0,currentSubset);
        return ans;
    }
};