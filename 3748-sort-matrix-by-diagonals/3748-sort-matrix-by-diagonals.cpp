class Solution {
public:
    void sortBottomLeft(vector<vector<int>>& grid){
        int prevRow=0, currentCol = 0;
        while(prevRow<grid.size()){
            int currentRow = prevRow;
            vector<int>diag;
            while(currentRow<grid.size() && currentCol<grid[0].size()){
                diag.push_back(grid[currentRow][currentCol]);
                currentRow++;
                currentCol++;
            }
            sort(diag.begin(), diag.end(), greater<>());
            // put the elements back!
            int i = 0;
            currentRow = prevRow;
            currentCol=0;
            while(currentRow<grid.size() && currentCol<grid[0].size()){
                grid[currentRow][currentCol] = diag[i];
                i++;
                currentRow++;
                currentCol++;
            }
            // reset the variables!
            prevRow++;
            currentCol=0;
        }
    }
    void sortTopRight(vector<vector<int>>& grid){
        int prevCol = 1, currentRow = 0;
        while(prevCol<grid.size()){
            int currentCol = prevCol;
            vector<int>diag;
            while(currentRow<grid.size() && currentCol<grid[0].size()){
                diag.push_back(grid[currentRow][currentCol]);
                currentRow++;
                currentCol++;
            }
            sort(diag.begin(), diag.end());
            // put the elements back!
            int i = 0;
            currentCol = prevCol;
            currentRow=0;
            while(currentRow<grid.size() && currentCol<grid[0].size()){
                grid[currentRow][currentCol] = diag[i];
                i++;
                currentRow++;
                currentCol++;
            }
            // reset the variables!
            prevCol++;
            currentRow=0;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        sortBottomLeft(grid);
        sortTopRight(grid);
        return grid;

    }
};