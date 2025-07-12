class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n);
        vector<int> indegree(n, 0);
        for (auto& rel : relations) {
            int u = rel[0] - 1;
            int v = rel[1] - 1;
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int>timeTaken(n);
        for(int i=0;i<n;i++){
            timeTaken[i] = time[i];
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int qn = q.size();
            for(int i=0;i<qn;i++){
                int node = q.front();
                q.pop();
                // relax the edges!
                for(int neighbour : adj[node]){
                    timeTaken[neighbour] = max(timeTaken[neighbour], timeTaken[node]+time[neighbour]);
                    indegree[neighbour]--;
                    if (indegree[neighbour] == 0) {
                        q.push(neighbour);
                    }
                }
                
            }
        }
        return  *max_element(timeTaken.begin(), timeTaken.end());

    }
};