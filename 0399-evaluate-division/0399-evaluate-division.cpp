class Solution {
public:
    double findValue(string startNode, string endNode,unordered_map<string, vector<pair<string,double>>>&adj){
        if(adj.find(startNode) == adj.end() || adj.find(endNode) == adj.end()) return -1.0;
        queue<pair<string,double>> q;
        set<string>vis;
        q.push({startNode,1.0});
        vis.insert(startNode);
        while(!q.empty()){
            string currentNode = q.front().first;
            double currentValue = q.front().second;
            q.pop();
            if(currentNode == endNode){
                return currentValue;
            }
            for(auto it : adj[currentNode]){
                if(vis.find(it.first) == vis.end()){
                    double newValue = currentValue * it.second;
                    q.push({it.first, newValue});
                    vis.insert(it.first);
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int maxNodes = equations.size() * 2;
        unordered_map<string, vector<pair<string,double>>> adj;
        for(int i = 0;i<equations.size();i++){
            string startNode = equations[i][0];
            string endNode = equations[i][1];
            double value = values[i];
            adj[startNode].push_back({endNode,value});
            adj[endNode].push_back({startNode,1.0/value});
        }
        vector<double> ans;
        for(int i = 0;i<queries.size();i++){
            double tempAns = findValue(queries[i][0], queries[i][1],adj);
            ans.push_back(tempAns);
        }
        return ans;
    }
};