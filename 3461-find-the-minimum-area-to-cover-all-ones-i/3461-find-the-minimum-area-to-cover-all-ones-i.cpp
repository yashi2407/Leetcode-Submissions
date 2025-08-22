class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),false));
        int minRow = INT_MAX, minCol = INT_MAX, maxRow = INT_MIN, maxCol = INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    minRow = min(minRow,i);
                    maxRow = max(maxRow,i);
                    minCol = min(minCol,j);
                    maxCol = max(maxCol,j);
                }
            }
        }
        int breadth = maxRow - minRow + 1;
        int length = maxCol - minCol + 1;
        return breadth*length;
    }
};