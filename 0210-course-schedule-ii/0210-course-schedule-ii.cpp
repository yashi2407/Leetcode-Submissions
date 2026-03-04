class Solution {
public:
    bool dfs(int course,vector<bool>&vis,stack<int>&st,vector<vector<int>>&adj,vector<bool>&pathVis){
        vis[course]= true;
        pathVis[course] = true;
        for(auto it : adj[course]){
            if(!vis[it]){
                if(dfs(it,vis,st,adj,pathVis)){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        st.push(course);
        pathVis[course] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            // [u,v] implies v->u.
            adj[v].push_back(u);
        }

        vector<bool>vis(numCourses,false);
        vector<bool>pathVis(numCourses,false);
        stack<int>st;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,st,adj,pathVis)){
                    return {};
                }
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

    }
};