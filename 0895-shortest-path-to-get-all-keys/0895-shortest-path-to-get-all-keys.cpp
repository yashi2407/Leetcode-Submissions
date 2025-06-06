class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int keysMask = 0;

        queue<tuple<int, int, int, int>> q;  // row, col, keysBitmask, steps
        set<tuple<int, int, int>> vis;       // row, col, keysBitmask

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    q.push({i, j, 0, 0});
                    vis.insert({i, j, 0});
                } else if (islower(grid[i][j])) {
                    keysMask |= (1 << (grid[i][j] - 'a'));
                }
            }
        }

        int delRow[4] = {0, +1, 0, -1};
        int delCol[4] = {-1, 0, +1, 0};

        while (!q.empty()) {
            auto [row, col, keysMaskCurrent, distance] = q.front();
            q.pop();

            char cell = grid[row][col];
            if (islower(cell)) {
                keysMaskCurrent |= (1 << (cell - 'a'));
                if (keysMaskCurrent == keysMask) return distance;
            }

            for (int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n) continue;
                char nextCell = grid[newRow][newCol];

                // Wall check
                if (nextCell == '#') continue;

                // Lock check: skip if we don't have the key
                if (isupper(nextCell) && !(keysMaskCurrent & (1 << (nextCell - 'A')))) {
                    continue;
                }

                // State not visited yet?
                if (vis.count({newRow, newCol, keysMaskCurrent}) == 0) {
                    vis.insert({newRow, newCol, keysMaskCurrent});
                    q.push({newRow, newCol, keysMaskCurrent, distance + 1});
                }
            }
        }

        return -1;
    }
};
