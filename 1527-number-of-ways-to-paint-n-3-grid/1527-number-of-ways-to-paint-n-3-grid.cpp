class Solution {
public:
    vector<string>possibleStates;
    int M = 1e9+7;
    vector<vector<int>> dp;
    void generatePossibleStates(int index, char prev, string current){
        if(index>=3){
            possibleStates.push_back(current);
            return;
        }
        // possible combinations
        for(char c : {'R','G','Y'}){
            if(c==prev){
                continue;
            }
            generatePossibleStates(index+1,c,current+c);
        }
    }

    int util(int row , int prevIndex, int n){
        if(row >=n){
            return 1;
        }
        if(dp[row][prevIndex]!=-1){
            return dp[row][prevIndex];
        }
        string prev = possibleStates[prevIndex];
        int ways = 0;
        for(int i=0;i<possibleStates.size();i++){
            if(i==prevIndex){
                continue;
            }
            string current = possibleStates[i];
            bool isValid = true;
            for(int j=0;j<3;j++){
                if(prev[j]==current[j]){
                    isValid = false;
                    break;
                }
            }
            if(isValid){
                ways = (ways + util(row+1,i,n)) %M;
            }

        }
        return dp[row][prevIndex] = ways;
    }
    int numOfWays(int n) {
        generatePossibleStates(0,'#',"");
        dp.assign(n+2, vector<int>(possibleStates.size()+1, -1));
        int res = 0;
        for(int i=0;i<possibleStates.size();i++){
            res = (res + util(1,i,n))% M;
        }
        return res;
    }
};