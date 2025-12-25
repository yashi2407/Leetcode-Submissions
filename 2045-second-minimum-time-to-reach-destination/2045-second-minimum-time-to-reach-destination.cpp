class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n);
        // create adjacency matrix.
        // make it zero based
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]-1].push_back(edges[i][1]-1);
            adj[edges[i][1]-1].push_back(edges[i][0]-1);
        }
        vector<int>best(n,INT_MAX);
        vector<int>secondBest(n,INT_MAX);
        best[0]=0;
        // node, current time.
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [currTime,node] = pq.top();
            pq.pop();

            // traverse the neighbours of the currentNode
            for(auto it : adj[node]){
                int depart = currTime;
                if ((depart/change) % 2 == 1) depart = (depart/change + 1) * change;
                int newTime = depart + time;

                // update the best time and second best time!
                if(best[it]>newTime){
                    secondBest[it] = best[it];
                    best[it] = newTime;
                    pq.push({newTime,it});
                }
                else if (newTime > best[it] && newTime < secondBest[it]) {
                    secondBest[it] = newTime;
                    pq.push({newTime, it});
                }


            }
        }
        return secondBest[n-1];
    }
};