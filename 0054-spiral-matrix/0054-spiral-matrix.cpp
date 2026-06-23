class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int leftColumn = 0;
        int rightColumn = matrix[0].size()-1;
        int topRow = 0;
        int bottomRow = matrix.size()-1;
        vector<int>ans;
        while(topRow<=bottomRow && leftColumn<=rightColumn){
            // print top row from left column to right
            for(int i=leftColumn;i<=rightColumn;i++){
                ans.push_back(matrix[topRow][i]);
            }
            topRow++;
            // print rightColumn from top row to bottom row
            for(int i=topRow;i<=bottomRow;i++){
                ans.push_back(matrix[i][rightColumn]);
            }
            rightColumn--;
            // print bottomRow from rightColumn to leftColumn
            if (topRow <= bottomRow) {
                for(int i=rightColumn;i>=leftColumn;i--){
                    ans.push_back(matrix[bottomRow][i]);
                }
                bottomRow--;
            }
            // print leftColumn from bottomRow to topRow
            // first check if column exixts?
            if(leftColumn<=rightColumn){
                for(int i = bottomRow;i>=topRow;i--){
                    ans.push_back(matrix[i][leftColumn]);
                }
                leftColumn++;
            }
        }
        return ans;
    }
};