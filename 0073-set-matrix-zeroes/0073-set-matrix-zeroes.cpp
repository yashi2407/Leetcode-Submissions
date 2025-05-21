class Solution {
public:
    void makeZero(int row, int col, vector<vector<int>>& matrix) {
        for(int i=0;i<matrix[0].size();i++){
            matrix[row][i]=0;
        }
         for(int i=0;i<matrix.size();i++){
            matrix[i][col]=0;
        }
        
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeroLoc;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    zeroLoc.push_back({i,j});
                }
            }
        }
        for(int i=0;i<zeroLoc.size();i++){
            int row = zeroLoc[i].first;
            int col = zeroLoc[i].second;
            makeZero(row,col, matrix);
        }
    }
};