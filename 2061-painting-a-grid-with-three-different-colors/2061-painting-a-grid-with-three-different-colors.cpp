class Solution {
public:
    vector<string>columnStates;
    int M = 1e9+7;
    vector<vector<int>> dp;
    void generateColumnsStates(int currentRow, char prevColour,int m, string current){
        if(currentRow==m){
            columnStates.push_back(current);
            return;
        }
        // loop over all the choices
        for(char ch :{'R','G', 'B'}){
            if(ch == prevColour){
                continue;
            }
            generateColumnsStates(currentRow+1,ch,m,current+ch);
        }
    }

    int solve(int currentCol, int n , int prevStateIndex){
        if(currentCol == n){
            return 1;
        }
        if(dp[currentCol][prevStateIndex]!=-1){
            return dp[currentCol][prevStateIndex];
        }
        int ways = 0;
        string prevState = columnStates[prevStateIndex];
        for(int i=0;i<columnStates.size();i++){
            string nextState = columnStates[i];
            bool isValid = true;
            for(int j=0;j<prevState.size();j++){
                if(prevState[j]==nextState[j]){
                    isValid = false;
                    break;
                }
            }
            if(isValid){
                ways = (ways + solve(currentCol+1,n,i)) % M;
            }
        }
        return dp[currentCol][prevStateIndex]= ways;
    }
    int colorTheGrid(int m, int n) {
        generateColumnsStates(0,'#',m,"");
        int k = columnStates.size();
        dp.assign(n, vector<int>(k, -1));
        int result = 0;
        for(int i=0;i<columnStates.size();i++){
            result = (result + solve(1, n, i)) % M;
        }
        return result % M;
    }
};