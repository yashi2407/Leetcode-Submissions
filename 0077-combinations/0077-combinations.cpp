class Solution {
public:
    void util(vector<vector<int>> &ans, int k, int currentNumber, int n, vector<int>&currentCombination){
        // Base Condition
        if(currentNumber > n){
            if(k == 0){
                ans.push_back(currentCombination);
            }
            return;
        }
        // pick the current number if possible
        if(k>0){
            currentCombination.push_back(currentNumber);
            util(ans,k-1,currentNumber+1,n,currentCombination);
            currentCombination.pop_back();
        }
        // don't pick the current Number
        util(ans,k,currentNumber+1,n,currentCombination);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        int currentNumber = 1;
        vector<int> currentCombination;
        util(ans,k,currentNumber,n,currentCombination);
        return ans;
    }
};