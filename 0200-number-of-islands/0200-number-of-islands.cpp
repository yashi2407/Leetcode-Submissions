class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        int delRow[4]={0,+1,0,-1};
        int delCol[4]={-1,0,+1,0};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newRow = row+delRow[i];
                int newCol = col+delCol[i];
                if(newRow>=0 && newRow<grid.size() && newCol>=0 && newCol<grid[0].size() && grid[newRow][newCol] ==
                '1')
                {
                    grid[newRow][newCol] = 0;
                    q.push({newRow,newCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int island=0;
        for(int i =0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]== '1'){
                    island++;
                    grid[i][j] = 0;
                    bfs(grid,i,j);
                }
            }
        }
        return island;
    }
};