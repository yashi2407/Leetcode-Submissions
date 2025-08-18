class Solution {
public:
    int findUltimateParent(int node, vector<int>&parent){
        if(parent[node]!= node){
            return parent[node]= findUltimateParent(parent[node],parent);
        }
        return node;
    }
    void unionByRank(int u, int v, vector<int>&parent, vector<int>&rank){
        int ultimateParentU = findUltimateParent(u,parent);
        int ultimateParentV = findUltimateParent(v,parent);

        if(ultimateParentU == ultimateParentV) return;

        // if rank is same, connect u with v and increase rank
        if(rank[ultimateParentU] == rank[ultimateParentV]){
            parent[ultimateParentV]=ultimateParentU;
            rank[ultimateParentU]++;
        }
        else if(rank[ultimateParentU] > rank[ultimateParentV]){
            parent[ultimateParentV]=ultimateParentU;
        }
        else{
            parent[ultimateParentU]=ultimateParentV;
        }

    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int>rank(n,1);
        for(int i=0;i<allowedSwaps.size();i++){
            int u = allowedSwaps[i][0];
            int v = allowedSwaps[i][1];
            unionByRank(u,v,parent,rank);
        }

        unordered_map<int, vector<int>> group;
        for(int i=0;i<n;i++){
            int root = findUltimateParent(i,parent);
            group[root].push_back(i);
        }
        int hammingDistance = 0;

        for (auto it : group){
            vector<int> indices = it.second;

            unordered_map<int,int>mp;
            for(int i = 0;i<indices.size();i++){
                // get the count of values present in traget array!
                mp[target[indices[i]]]++;
            }

            // see if we can find the same values in source array
            for(int i = 0;i<indices.size();i++){
                int sourceValue = source[indices[i]];
                // source value in map, yes, can be swapper. No hamming distance
                if(mp.find(sourceValue)!=mp.end() && mp[sourceValue]>0){
                    mp[sourceValue]--;
                }
                else{
                    hammingDistance++;
                }
            }
        }
        return hammingDistance;
    }
};