class Solution {
public:
    vector<int>delRow = {-1,0,+1,0};
    vector<int>delCol = {0,+1,0,-1};

    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>&vis){
        vis[row][col] = true;
        for(int i=0;i<4;i++){
            int newRow = row+delRow[i];
            int newCol = col+delCol[i];
            if(newRow<board.size() && newRow>=0 && newCol<board[0].size()&& newCol>=0 &&!vis[newRow][newCol] && board[newRow][newCol] == 'X'){
                dfs(newRow,newCol,board,vis);
            }
        }

    }
    int countBattleships(vector<vector<char>>& board) {
        vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size(),false));
        int count = 0;
        for(int i = 0; i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] == 'X' && !vis[i][j]){
                    count++;
                    dfs(i,j,board,vis);
                }
            }
        }
        return count;
    }
};