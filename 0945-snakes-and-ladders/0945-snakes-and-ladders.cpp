class Solution {
public:
    pair<int, int> getPosition(int num, int n) {
        int rowFromBottom = (num - 1) / n;
        int row = n - 1 - rowFromBottom; // Convert to top-down row index
        int colInRow = (num - 1) % n;

        int col;
        if (rowFromBottom % 2 == 0) {
            col = colInRow; // Left to right
        } else {
            col = n - 1 - colInRow; // Right to left
        }
        return {row, col};
    }
    int getNumber(int row, int col, int n) {
        int rowFromBottom = n - 1 - row;
        int base = rowFromBottom * n;
        
        if (rowFromBottom % 2 == 0) {
            return base + col + 1;
        } else {
            return base + (n - col);
        }
    }


    int snakesAndLadders(vector<vector<int>>& board) {
        queue<pair<int,int>>q;
        int n = board.size();
        q.push({1,0});
        vector<bool> visited(n*n + 1, false);
        while(!q.empty()){
            int number = q.front().first;
            int distance = q.front().second;
            q.pop();
            if(number == n*n){
                return distance;
            }
            pair<int,int>coordinates = getPosition(number,n);
            //possible moves
            for(int i =1;i<=6 && number + i <= n * n;i++){
                int next = number + i;
                pair<int, int> newCoordinates = getPosition(next,n);
                int r = newCoordinates.first;
                int c = newCoordinates.second;
                int nextVal = (board[r][c] != -1) ? board[r][c] : next;
                if (!visited[nextVal]) {
                    visited[nextVal] = true;
                    q.push({nextVal, distance + 1});
                }
            }

        }
        return -1;
    }
};