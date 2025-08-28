class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // queue: row, col, dist, remaining_k
        queue<array<int,4>> q;
        q.push({0,0,0,k});

        // visited: {row, col, remaining_k}
        set<array<int,3>> vis;
        vis.insert({0,0,k});

        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};

        while (!q.empty()) {
            auto [currentRow, currentCol, dist, rem] = q.front();
            q.pop();
            if (currentRow == m-1 && currentCol == n-1) {
                return dist;
            }
            for (int d = 0; d < 4; d++) {
                int newRow = currentRow + delRow[d];
                int newCol = currentCol + delCol[d];
                // bounds check
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n) continue;

                int newRem = rem - grid[newRow][newCol]; // spend budget if obstacle
                if (newRem < 0) continue; // can't pass
                array<int,3> state = {newRow,newCol,newRem};
                if (!vis.count(state)) {
                    vis.insert(state);
                    q.push({newRow,newCol,dist+1,newRem});
                }
            }
        }
        return -1;
    }
};
