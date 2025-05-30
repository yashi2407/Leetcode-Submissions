class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj, int node) {
        int n = adj.size();
        vector<int> distance(n, -1);
        queue<int> q;
        q.push(node);
        distance[node] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int neighbor : adj[curr]) {
                if (distance[neighbor] == -1) {
                    distance[neighbor] = distance[curr] + 1;
                    q.push(neighbor);
                }
            }
        }

        return distance;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<vector<int>>adj(edges.size());
        int n = edges.size();
        for(int i = 0;i<edges.size();i++){
            int parent = i;
            int child = edges[i];
            if(child !=-1){
                adj[parent].push_back(child);
            }
        }
        vector<int> dist1 = bfs(adj, node1);
        vector<int> dist2 = bfs(adj, node2);

        int result = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};