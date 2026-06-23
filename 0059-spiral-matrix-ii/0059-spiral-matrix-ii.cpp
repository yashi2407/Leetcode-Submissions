class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int leftColumn = 0;
        int rightColumn = n-1;
        int topRow = 0;
        int bottomRow = n-1;
        int currentnumber = 1;
        vector<vector<int>>matrix(n,vector<int>(n,1));
        while(topRow<=bottomRow && leftColumn<=rightColumn){
            for(int i=leftColumn;i<=rightColumn;i++){
                matrix[topRow][i] = currentnumber++ ;
            }
            topRow++;
            for(int i=topRow;i<=bottomRow;i++){
                matrix[i][rightColumn] = currentnumber++;
            }
            rightColumn--;
            if (topRow <= bottomRow) {
                for(int i=rightColumn;i>=leftColumn;i--){
                    matrix[bottomRow][i] = currentnumber++;
                }
                bottomRow--;
            }
            if(leftColumn<=rightColumn){
                for(int i = bottomRow;i>=topRow;i--){
                    matrix[i][leftColumn] = currentnumber++;
                }
                leftColumn++;
            }
        }
        return matrix;
    }
};