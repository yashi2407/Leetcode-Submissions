class Solution {
public:
    int result = INT_MAX;
    vector<vector<int>> rotateClockWise(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> rotatedGrid(n, vector<int>(m));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rotatedGrid[j][m-i-1] = grid[i][j];
            }
        }

        return rotatedGrid;
    }

    int minimumArea(int startRow, int endRow, int startCol, int endCol, vector<vector<int>>& grid) {
        int m = grid.size(); //Rows
        int n = grid[0].size(); //Columns

        int minRow = m;
        int maxRow = -1;
        int minCol = n;
        int maxCol = -1;

        for(int i = startRow; i < endRow; i++) {
            for(int j = startCol; j < endCol; j++) {
                if(grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);

                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }       
            }
        }
        if (maxRow == -1) return 0;
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    } 
    int utilCaseOneandTwo(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int temp  = INT_MAX;

        for(int rowSplit = 1; rowSplit < m; rowSplit++){
            for(int colSplit = 1; colSplit<n; colSplit++){

                    // case - 1
                    int topRectangle = minimumArea(0,rowSplit, 0,n,grid);
                    int bottomLeft = minimumArea(rowSplit,m, 0, colSplit, grid);
                    int bottomRight = minimumArea(rowSplit,m,colSplit,n,grid);

                    temp = min(temp, topRectangle+bottomLeft+bottomRight);


                    // case - 2
                    int topLeft = minimumArea(0, rowSplit, 0, colSplit, grid);
                    int topRight = minimumArea(0, rowSplit, colSplit, n, grid);
                    int bottom = minimumArea(rowSplit, m, 0, n, grid);
                    temp = min(temp,topLeft+topRight+bottom);
            }
        }
        return temp;
    }

    int utilCaseThree(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int temp  = INT_MAX;
        // case - 3
        for(int rowSplit1 = 1;rowSplit1<m;rowSplit1++){
            for(int rowSplit2 = rowSplit1+1; rowSplit2<m;rowSplit2++){
                int top = minimumArea(0,rowSplit1,0,n,grid);
                int middle = minimumArea(rowSplit1,rowSplit2,0,n,grid);
                int bottom = minimumArea(rowSplit2,m,0,n,grid);

                temp = min(temp,top+middle+bottom);
            }
        }
        return temp;
    }
    int minimumSum(vector<vector<int>>& grid) {
        result = min(result,utilCaseOneandTwo(grid));
        result = min(result,utilCaseThree(grid));

        // rotate the matrix
        vector<vector<int>> rotatedGrid = rotateClockWise(grid);
        result = min(result,utilCaseOneandTwo(rotatedGrid));
        result = min(result,utilCaseThree(rotatedGrid));
        return result;
        
    }
};