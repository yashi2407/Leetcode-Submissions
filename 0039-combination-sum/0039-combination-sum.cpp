class Solution {
public:
    void solve(vector<int>& candidates, int target ,vector<vector<int>>&ans,vector<int>&currentCombinations, int currentIndex){
        if(currentIndex>=candidates.size()){
            if(target == 0){
                ans.push_back(currentCombinations);
            }
            return;
        }

        // if possible to pick!
        if(candidates[currentIndex]<=target){
            //choose the element
            currentCombinations.push_back(candidates[currentIndex]);
            solve(candidates,target-candidates[currentIndex],ans,currentCombinations, currentIndex);
            currentCombinations.pop_back();
        }
        solve(candidates,target,ans,currentCombinations, currentIndex+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currentCombinations;
        solve(candidates,target,ans,currentCombinations, 0);
        return ans;
    }
};