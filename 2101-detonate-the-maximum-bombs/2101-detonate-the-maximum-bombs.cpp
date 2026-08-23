class Solution {
public:
    int bfs(int startNode, vector<vector<int>> &adj){
        queue<int>q;
        vector<int>vis(adj.size(),0);
        vis[startNode] = 1;
        q.push(startNode);
        int ans = 0;
        while(!q.empty()){
            int currentBombIndex = q.front(); 
            q.pop();
            ans++;
            for(auto &it:adj[currentBombIndex]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> adj(bombs.size());
        for (int i = 0; i < bombs.size(); i++) {
            int xi = bombs[i][0];
            int yi = bombs[i][1];
            int ri = bombs[i][2];

            for (int j = 0; j < bombs.size(); j++) {
                if (i == j) {
                    continue;
                }

                int xj = bombs[j][0];
                int yj = bombs[j][1];

                long long dx = xj - xi;
                long long dy = yj - yi;

                if (dx * dx + dy * dy <= 1LL * ri * ri) {
                    adj[i].push_back(j);
                }
            }
        }

        // now BFS from every bomb
        int ans = 0;
        for (int i = 0; i < bombs.size(); i++) {
            ans = max(ans, bfs(i, adj));
        }
        
        return ans;
    }
};