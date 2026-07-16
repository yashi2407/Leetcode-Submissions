class Solution {
public:
    vector<int> delRow = {-1,-1,0,+1,+1,+1,0,-1};
    vector<int> delCol = {0,+1,+1,+1,0,-1,-1,-1,0};
    int getLiveCells(vector<vector<int>>& board, int row, int col){
        int live = 0;
        for(int i=0;i<8;i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            if(newRow>=0 && newRow<board.size() && newCol >=0 && newCol<board[0].size()){
                if(board[newRow][newCol] == 1 || board[newRow][newCol] == 3){
                    live++;
                }
            }
        }
        return live;
    }
    void gameOfLife(vector<vector<int>>& board) {
        //0->1 = 2
        //1->0 = 3
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == 1){
                    int live = getLiveCells(board,i,j);
                    if(live<2){
                        board[i][j] = 3;
                    }
                    if(live>3){
                        board[i][j] = 3;
                    }
                }
                else {
                    int live = getLiveCells(board,i,j);
                    if(live == 3){
                        board[i][j] = 2;
                    }
                    
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == 2){
                    board[i][j] = 1;
                }
                else if(board[i][j] == 3){
                    board[i][j] = 0;
                }
            }
        }
    }
};