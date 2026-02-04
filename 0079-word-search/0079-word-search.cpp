class Solution {
public:
bool backtrack(vector<vector<char>>& board, string word,vector<vector<bool>>&vis, int index, int row, int col){
        if(index >= word.size()){
            return true;
        }
        if(row>=board.size() || row<0 || col>=board[0].size() || col<0){
            return false;
        }
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        for(int k =0;k<4;k++){
            int nRow = row+delRow[k];
            int nCol = col+delCol[k];
            if(nRow >= 0 && nRow < board.size() && nCol >= 0 && nCol < board[0].size() && 
               vis[nRow][nCol] == false && board[nRow][nCol] == word[index]) {
                vis[nRow][nCol]=true;
                if(backtrack(board,word,vis,index+1,nRow,nCol)){
                    return true;
                }
                vis[nRow][nCol]=false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>vis(board.size(), vector<bool>(board[0].size(),false));
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] == word[0] && !vis[i][j]){
                    // start the algo
                    vis[i][j]= true;
                    if(backtrack(board,word,vis,1,i,j)){
                        return true;
                    }
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};