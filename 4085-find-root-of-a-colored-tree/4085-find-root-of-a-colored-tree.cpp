
class Solution {
public:
    char getNextColor(char color) {
        if (color == 'R') return 'B';
        if (color == 'B') return 'W';
        return 'R';
    }

    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<int>outDegree(n,0);
        vector<int>inDegree(n,0);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(getNextColor(colors[u]) == colors[v]){
                // u->v is valid
                inDegree[v]++;
                outDegree[u]++;
            }
            else if (getNextColor(colors[v]) == colors[u]) {
                inDegree[u]++;
                outDegree[v]++;
            }
            else {
                return -1;
            }
        }

        int root = -1;
        for (int i = 0; i < n; i++) {
            if (outDegree[i] > 2)
                return -1;

            if (inDegree[i] == 0) {
                if (root != -1) // only one root should exist!
                    return -1;
                root = i;
            }
            else if (inDegree[i] != 1) {
                return -1;
            }
        }

        return root;
    }
};
