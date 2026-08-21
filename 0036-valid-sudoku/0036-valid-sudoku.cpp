class Solution {
public:
    bool isValid(int startRow, int startCol,vector<vector<char>>& board){
        unordered_set<char>set;
        for(int i = startRow; i<startRow+3;i++){
            for(int j= startCol;j<startCol+3;j++){
                if(board[i][j]== '.'){
                    continue;
                }
                if(set.find(board[i][j])!= set.end()){
                    return false;
                }
                set.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // validate row
        for(int i = 0;i<9;i++){
            unordered_set<char>set;
            for(int j= 0;j<9;j++){
                if(board[i][j]== '.'){
                    continue;
                }
                if(set.find(board[i][j])!= set.end()){
                    return false;
                }
                set.insert(board[i][j]);
            }
        }
        // validate each column!!
        for(int j = 0;j<9;j++){
            unordered_set<char>set;
            for(int i= 0;i<9;i++){
                if(board[i][j]== '.'){
                    continue;
                }
                if(set.find(board[i][j])!= set.end()){
                    return false;
                }
                set.insert(board[i][j]);
            }
        }
        // validate eacc 3*3 matrix!
        for(int startRow = 0; startRow<9;startRow+=3){
            for(int startCol = 0; startCol<9;startCol+=3){
                if(!isValid(startRow,startCol,board)){
                    return false;
                }
            }
        }
        return true;
    }
};