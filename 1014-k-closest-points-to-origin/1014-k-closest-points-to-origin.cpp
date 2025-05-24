class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> maxHeap;
        for(int i = 0; i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            maxHeap.push({dist,{x,y}});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        while(maxHeap.size()>0){
            vector<int>coordinates;
            coordinates.push_back(maxHeap.top().second.first);
            coordinates.push_back(maxHeap.top().second.second);
            ans.push_back(coordinates);
            maxHeap.pop();
        }
        return ans;
    }
};