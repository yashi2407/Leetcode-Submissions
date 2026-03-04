class Solution {
public:
    bool isSpecial(vector<vector<int>>& mat, int i, int j){
        // check for ith row
        for(int col = 0; col<mat[0].size();col++){
            if(mat[i][col] == 1 && col != j){
                return false;
            }
        }
        // check for jth row
        for(int row = 0; row<mat.size();row++){
            if(mat[row][j] == 1 && row != i){
                return false;
            }
        }
        return true;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        for(int i = 0;i<mat.size();i++){
            for(int j = 0; j<mat[0].size();j++){
                if( mat[i][j] == 1){
                    if(isSpecial(mat,i,j)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};