class Solution {
public:
    void util(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int>&combination, int index){
        if(target == 0){
            ans.push_back(combination);
            return;
        }
        for(int i = index;i<candidates.size();i++){
            if(i>index && candidates[i-1] == candidates[i]){
                continue;
            }
            if(target<candidates[i]){
                break;
            }
            combination.push_back(candidates[i]);
            util(candidates,target-candidates[i],ans,combination,i+1);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combination;
        util(candidates, target, ans,combination,0);
        return ans;
    }
};