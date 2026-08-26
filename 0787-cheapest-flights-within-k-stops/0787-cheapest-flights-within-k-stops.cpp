class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            int source = flights[i][0];
            int destination = flights[i][1];
            int weight = flights[i][2];
            adj[source].push_back({destination,weight}); 
        }
        // k, cost, node
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>distance(n,INT_MAX);
        distance[src] = 0;
        pq.push({0,{0,src}});
        while(!pq.empty()){
            auto [currentK, temp] = pq.top();
            auto [currentCost, currentNode] = temp;
            pq.pop();
            for(auto it:adj[currentNode]){
                if(distance[it.first]> currentCost + it.second && currentK<=k){
                    distance[it.first] = currentCost + it.second;
                    pq.push({currentK+1,{distance[it.first], it.first}});
                }
            }

        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};