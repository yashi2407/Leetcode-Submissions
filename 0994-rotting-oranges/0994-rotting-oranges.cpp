class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshCount = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }
        int time = -1;
        int delRow[] = {0, 0, -1, 1};
        int delCol[] = {1, -1, 0, 0};
        if(freshCount == 0){
            return 0;
        }
        while(!q.empty()){
            int size = q.size();
            time++;
            for(int i = 0;i<size;i++){
                auto it = q.front();
                int row = it.first;
                int col = it.second;
                q.pop();
                for(int j = 0;j<4;j++){
                    int nRow = row + delRow[j];
                    int nCol = col + delCol[j];
                    if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && grid[nRow][nCol]== 1){
                        freshCount--;
                        q.push({nRow,nCol});
                        grid[nRow][nCol] = 2;
                    }
                }
            }
        }
        return freshCount == 0 ? time : -1;
    }
};