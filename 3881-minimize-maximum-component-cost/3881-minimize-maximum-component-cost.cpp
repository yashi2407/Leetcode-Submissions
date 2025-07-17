class Solution {
public:
    int findUltimateParent(vector<int> &ultimateParent, int node){
        if(ultimateParent[node] == node){
            return node;
        }
        return ultimateParent[node] = findUltimateParent(ultimateParent,ultimateParent[node]);
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        if(k>=n){
            return 0;
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2]; // compare by weight (third element)
        });

        int numberOfcomponents = n;
        int cost = 0;
        vector<int> ultimateParent(n);
        for(int i=0;i<n;i++){
            ultimateParent[i]= i;
        }
        vector<int>rank(n,0);

        for(int i=0;i<edges.size();i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            int currentCost = edges[i][2];

            int ultimateParentNode1 = findUltimateParent(ultimateParent,node1);
            int ultimateParentNode2 = findUltimateParent(ultimateParent,node2);
            if (ultimateParentNode1 != ultimateParentNode2) {
                int rank1 = rank[ultimateParentNode1];
                int rank2 = rank[ultimateParentNode2];

                // if same rank, join anyone with anyone
                if (rank1 == rank2) {
                    ultimateParent[ultimateParentNode2] = ultimateParentNode1;
                    rank[ultimateParentNode1]++;
                } else if (rank1 > rank2) {
                    ultimateParent[ultimateParentNode2] = ultimateParentNode1;
                } else {
                    ultimateParent[ultimateParentNode1] = ultimateParentNode2;
                }
                numberOfcomponents--;
                cost = max(cost,currentCost);
                if(numberOfcomponents == k){
                    return cost;
                }
            }
        }
        return numberOfcomponents != k ? 0 : cost;
    }
};