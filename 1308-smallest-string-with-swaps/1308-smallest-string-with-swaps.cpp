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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int>rank(n,1);
        for(int i=0;i<pairs.size();i++){
            int u = pairs[i][0];
            int v = pairs[i][1];
            unionByRank(u,v,parent,rank);
        }

        // group indices by ultimate parent
        unordered_map<int, vector<int>> group;
        for(int i=0;i<n;i++){
            int root = findUltimateParent(i,parent);
            group[root].push_back(i);
        }

        // for each group: collect letters, sort, and put back

        for(auto it : group){
            vector<int>indices = it.second;
            string letters;
            for(int i=0;i<indices.size();i++){
                letters.push_back(s[indices[i]]);
            }
            sort(indices.begin(), indices.end());
            sort(letters.begin(), letters.end());

            for(int j=0;j<indices.size();j++){
                s[indices[j]] = letters[j];
            }
        }
        return s;
    }
};