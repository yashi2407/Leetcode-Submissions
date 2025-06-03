class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size(), ans = 0;
        queue<int> q;
        vector<bool> vis(n, false);
        vector<bool> boxAvailable(n, false);

        for (int box : initialBoxes) {
            q.push(box);
            boxAvailable[box] = true;
        }
        while (!q.empty()) {
            int box = q.front(); 
            q.pop();

            if (vis[box] || status[box] == 0) continue;

            vis[box] = true;
            ans += candies[box];

            for (int k : keys[box]) {
                status[k] = 1;
                if (boxAvailable[k]) {
                    q.push(k);
                }
            }

            for (int b : containedBoxes[box]) {
                boxAvailable[b] = true;
                q.push(b);  // always queue it, check open+vis later
            }
        }

        return ans;
    }
};