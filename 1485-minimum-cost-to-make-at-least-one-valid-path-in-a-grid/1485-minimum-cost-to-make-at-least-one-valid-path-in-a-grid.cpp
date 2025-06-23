class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int INF = 1e9;
        int m = grid.size();
        int n = grid[0].size();

        deque<tuple<int, int, int>> q;
        vector<vector<int>> cost(m, vector<int>(n, INF));
        cost[0][0] = 0;
        q.push_front({0, 0, 0});

        int delRow[4] = {0, 0, 1, -1};
        int delCol[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [currentCost, row, col] = q.front();
            q.pop_front();

            // Try moving in the sign's direction (0 cost)
            int d = grid[row][col] - 1;
            int tempRow = row + delRow[d];
            int tempCol = col + delCol[d];

            if (tempRow >= 0 && tempRow < m && tempCol >= 0 && tempCol < n) {
                if (currentCost < cost[tempRow][tempCol]) {
                    cost[tempRow][tempCol] = currentCost;
                    q.push_front({currentCost, tempRow, tempCol});
                }
            }

            // Try all other directions (1 cost)
            for (int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    int newCost = currentCost + 1;
                    if (newCost < cost[newRow][newCol]) {
                        cost[newRow][newCol] = newCost;
                        q.push_back({newCost, newRow, newCol});
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};
