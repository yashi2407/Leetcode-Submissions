class Solution {
public:
    int dfs(int node, vector<vector<int>>& graph, string& colors, vector<bool>& visited,
            vector<bool> &pathVisited, vector<vector<int>>& count) {
        
        visited[node] = true;
        pathVisited[node] = true;

        for (int neighbor : graph[node]) {
            if (pathVisited[neighbor]) return -1;
            if (!visited[neighbor]) {
                int res = dfs(neighbor, graph, colors, visited, pathVisited, count);
                if (res == -1) return -1;
            }
            for (int i = 0; i < 26; i++) {
                count[node][i] = max(count[node][i], count[neighbor][i]);
            }
        }

        count[node][colors[node] - 'a']++;
        pathVisited[node] = false;

        int maxColorFreq = 0;
        for (int i = 0; i < 26; i++) {
            maxColorFreq = max(maxColorFreq, count[node][i]);
        }
        return maxColorFreq;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<vector<int>> count(n, vector<int>(26, 0));
        vector<bool> visited(n, false), pathVisited(n, false);
        int result = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int res = dfs(i, graph, colors, visited, pathVisited, count);
                if (res == -1) return -1;
                result = max(result, res);
            }
        }

        return result;
    }
};
