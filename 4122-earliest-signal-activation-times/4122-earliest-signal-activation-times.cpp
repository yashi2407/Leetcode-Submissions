class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int t = edges[i][2];
            adj[u].push_back({v,t});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
        // time and delay
        q.push({0,0});
        vector<long long> activationTime(n,-1);
        activationTime[0] = 0;
        requiredSignals[0] = 1; 
        while(!q.empty()){
            int node = q.top().second;
            long long currentTime = q.top().first;
            requiredSignals[node]--;
            q.pop();
            if(requiredSignals[node] == 0){
                activationTime[node] = currentTime;
                for(auto it:adj[node]){
                    long long newDelay = currentTime + it.second;
                    q.push({newDelay,it.first});
                }
            }
        }
        return activationTime;
    }
};