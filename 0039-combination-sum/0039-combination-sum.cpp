class Solution {
public:
    void util(vector<int>& candidates, int target, int index, vector<vector<int>> &ans, vector<int>&currentAns){
        if(index ==candidates.size()){
            if(target == 0){
                ans.push_back(currentAns);
            }
            return;
        }
        // can pick
        if(candidates[index]<=target){
            currentAns.push_back(candidates[index]);
            util(candidates,target-candidates[index],index,ans,currentAns);
            currentAns.pop_back();
        }
        // won't pick
        util(candidates,target,index+1,ans,currentAns);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>currentAns;
        util(candidates,target,0,ans,currentAns);
        return ans;
    }
};