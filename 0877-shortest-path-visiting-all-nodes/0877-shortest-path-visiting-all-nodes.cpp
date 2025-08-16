class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n==0){
            return 0;
        }

        int totalDistance = 0;
        queue<pair<int,int>>q; // node and mask
        set<pair<int,int>> vis; // node and path mask

        for(int i=0;i<n;i++){
            int mask = 1<<i;
            q.push({i,mask});
            vis.insert({i,mask});
        }

        int allVisited = (1 << n) - 1;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                int currentNode = q.front().first;
                int currentMask = q.front().second;
                q.pop();

                if(currentMask == allVisited){
                    return totalDistance;
                }
                for(auto it : graph[currentNode]){
                    int newMask = currentMask | (1 << it);
                    if (vis.find({it, newMask}) == vis.end()){
                        vis.insert({it, newMask});
                        q.push({it, newMask});
                    }
                }
            }
            // distance is at current level
            totalDistance++;
        }
        return totalDistance;
    }
};