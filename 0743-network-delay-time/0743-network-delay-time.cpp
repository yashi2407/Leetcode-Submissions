class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // delay is 1 based vec
        vector<int>delay(n+1,INT_MAX);
        delay[k] = 0;
        // Make adj graph
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int srcNode = times[i][0];
            int destNode = times[i][1];
            int delayTime = times[i][2];
            adj[srcNode].push_back({destNode,delayTime});
        }
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,k});
        while(!pq.empty()){
            int currentNode = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto it:adj[currentNode]){
                if (dist > delay[currentNode]) continue;
                if(it.second + dist<delay[it.first]){
                    delay[it.first] = it.second + dist;
                    pq.push({it.second + dist, it.first});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<n+1;i++){
            if(delay[i] == INT_MAX){
                return -1;
            }
            ans = max(ans,delay[i]);
        }
        return ans;
    }
};