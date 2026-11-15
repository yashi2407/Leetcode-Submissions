class Solution {
public:
    int util(int u, vector<vector<int>>&adj,vector<int>& op, vector<int>& score){
        if(adj[u].size() == 0){
            return score[u];
        }
        long long sum = score[u];
        long long minChildScore = INT_MAX;
        for(auto it : adj[u]){
            long long childScore = util(it,adj,op,score);
            sum += childScore;
            minChildScore = min(minChildScore,childScore);
        }
        if(op[u] == 1){
            sum = sum - minChildScore;
        }
        else {
            sum = sum - min(0LL,minChildScore);
        }
        return sum;
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            int u = parent[i];
            int v = i;
            adj[u].push_back(v);
        }
        return util(0,adj,op,score);
    }
};