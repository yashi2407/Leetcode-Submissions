class Solution {
public:
    double bfs(string startNode, string endNode, unordered_map<string,vector<pair<string,double>>>&mp){
        set<string>vis;
        queue<pair<string,double>>q;
        q.push({startNode,1.0});
        while(!q.empty()){
            string currentNode = q.front().first;
            double currentAns = q.front().second;
            q.pop();
            if(currentNode == endNode){
                return currentAns;
            }
            for(auto it : mp[currentNode]){
                string nextNode = it.first;
                double edge = it.second;
                if(vis.find(nextNode) == vis.end()){
                    double nextAns = currentAns * edge;
                    q.push({nextNode, nextAns});
                    q.push({nextNode,currentAns});
                    vis.insert(nextNode);
                }
            }
        }
        return (double) -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>mp;
        vector<double> ans;
        for(int i = 0;i<equations.size();i++){
            string nodeOne = equations[i][0];
            string nodeTwo = equations[i][1];
            double value = values[i];
            mp[nodeOne].push_back({nodeTwo,value});
            mp[nodeTwo].push_back({nodeOne,(1/value)});
        }

        for(int i = 0; i <queries.size();i++){
            string startNode = queries[i][0];
            string endNode = queries[i][1];
            if(mp.find(startNode) == mp.end() || mp.find(endNode) == mp.end()){
                ans.push_back(-1.0);
            }
            else{
                // we do a traversal!
                double value = bfs(startNode, endNode, mp);
                ans.push_back(value);
            }
        }
        return ans;

    }
};