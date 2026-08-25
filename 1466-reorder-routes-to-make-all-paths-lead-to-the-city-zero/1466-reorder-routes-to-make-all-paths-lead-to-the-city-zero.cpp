class Solution {
public:
    int bfs(vector<vector<pair<int,bool>>>&newConnections,int n){
        vector<int> vis(n,-1);
        queue<int>q;
        vis[0] = 1;
        q.push(0);
        int ans = 0;
        while(!q.empty()){
            int currentNode = q.front();
            q.pop();
            for(auto it:newConnections[currentNode]){
                if(vis[it.first] == -1){
                    if(it.second == true){
                        ans++;
                    }
                    vis[it.first] = 1;
                    q.push(it.first);
                }
            }
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,bool>>>newConnections(n);
        for(int i=0;i<connections.size();i++){
            int node1 = connections[i][0];
            int node2 = connections[i][1];
            newConnections[node1].push_back({node2,true});   // needs reversal
            newConnections[node2].push_back({node1,false});  // already points toward 0
        }
        int ans = bfs(newConnections,n);
        return ans;
    }
};