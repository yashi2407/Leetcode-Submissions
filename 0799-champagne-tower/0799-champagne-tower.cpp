class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> ans(101, vector<double>(101,0.0));
        ans[0][0] = poured;
        for(int i=0;i<=query_row;i++){
            for(int j = 0;j<=query_glass;j++){
                if(ans[i][j]>1){
                    double extra = (ans[i][j]-1)/2;
                    ans[i][j] = 1;
                    ans[i+1][j] = ans[i+1][j] + extra;
                    ans[i+1][j+1] = ans[i+1][j+1] + extra;
                }
            }
        }
        return ans[query_row][query_glass];
    }
};