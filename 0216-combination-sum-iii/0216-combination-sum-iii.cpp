class Solution {
public:
    void solve(int k, int n, vector<vector<int>> &ans, vector<int> &currentCombination, int currentSum, int start){
        if(k==0){
            if(currentSum == n){
                ans.push_back(currentCombination);
            }
            return;
        }
        // try all the possible combinations from 1...9 which are available!
        for(int i=start;i<=9;i++){
            if (currentSum + i > n){
                return;
            } 
            currentCombination.push_back(i);
            solve(k-1,n,ans,currentCombination,currentSum+i,i+1);
            currentCombination.pop_back();   
            
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> currentCombination;
        solve(k,n,ans,currentCombination,0,1);
        return ans;
    }
};