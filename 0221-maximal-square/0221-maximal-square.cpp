class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> maxArea(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        int ans = 0;
        for(int i = matrix.size()-1;i>=0;i--){
            for(int j = matrix[0].size()-1;j>=0;j--){
                cout<<"i and j"<<i<<j<<endl;
                if(matrix[i][j] == '0'){
                    maxArea[i][j] = 0;
                    cout<<"maxArea"<<maxArea[i][j]<<endl;
                    ans = max(ans,maxArea[i][j]);
                }
                else {
                    // we look in three directions and they should be not zero!???
                    if(i == matrix.size()-1 || j == matrix[0].size()-1){
                        maxArea[i][j] = matrix[i][j] - '0';
                        cout<<"maxArea"<<maxArea[i][j]<<endl;
                        ans = max(ans,maxArea[i][j]);
                    }
                    else {
                        int prevArea = min(maxArea[i][j+1],min(maxArea[i+1][j+1], maxArea[i+1][j]));
                        maxArea[i][j] = prevArea+1;
                        cout<<"maxArea"<<maxArea[i][j]<<endl;
                        ans = max(ans,maxArea[i][j]);
                    }

                }
            }
        }
        return ans*ans;
    }
};