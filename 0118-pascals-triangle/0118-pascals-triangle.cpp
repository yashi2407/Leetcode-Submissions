class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>firstRow(1,1);
        ans.push_back(firstRow);
        if(numRows > 1){
            vector<int>secondRow(2,1);
            ans.push_back(secondRow);
        }
        for(int i=3;i<=numRows;i++){
            // make a vector of size i
            vector<int>currentRow(i,1);
            for(int j=1;j<=i-2;j++){
                currentRow[j] = ans[i-2][j-1] + ans[i-2][j];
            }
            ans.push_back(currentRow);
        }
        return ans;
    }
};