class Solution {
public:
    void solve(vector<int>& candidates, int target ,vector<vector<int>>&ans,vector<int>&currentCombinations, int currentIndex){
            if(target == 0){
                ans.push_back(currentCombinations);
                return;
            }
            // try all valid positions
            for(int i = currentIndex;i<candidates.size();i++){
                if(candidates[i]>target){
                    break;
                }
                currentCombinations.push_back(candidates[i]);
                solve(candidates, target-candidates[i], ans,currentCombinations,i);
                currentCombinations.pop_back();

        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currentCombinations;
        sort(candidates.begin(), candidates.end());
        solve(candidates,target,ans,currentCombinations, 0);
        return ans;
    }
};