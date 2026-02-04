class Solution {
public:
    void goRight(vector<vector<int>>& matrix,vector<int> &ans, int &i, int &j,vector<vector<int>> &vis){
        while(j<matrix[0].size() && !vis[i][j]){
            ans.push_back(matrix[i][j]);
            vis[i][j]= 1;
            j++;
        }
        j--;
    }
    void goDown(vector<vector<int>>& matrix,vector<int> &ans, int &i, int &j,vector<vector<int>> &vis){
        while(i<matrix.size() && !vis[i][j]){
            ans.push_back(matrix[i][j]);
            vis[i][j]= 1;
            i++;
        }
        i--;
    }
    void goLeft(vector<vector<int>>& matrix,vector<int> &ans, int &i, int &j,vector<vector<int>> &vis){
        while(j>=0 && !vis[i][j]){
            ans.push_back(matrix[i][j]);
            vis[i][j]= 1;
            j--;
        }
        j++;
    }
    void goUp(vector<vector<int>>& matrix,vector<int> &ans, int &i, int &j,vector<vector<int>> &vis){
        while(i>=0 && !vis[i][j]){
            ans.push_back(matrix[i][j]);
            vis[i][j]= 1;
            i--;
        }
        i++;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        vector<vector<int>> vis(matrix.size(),vector<int>(matrix[0].size(),0));
        int i=0;int j=0;
        int total = matrix.size() * matrix[0].size();

        while ((int)ans.size() < total) {
            goRight(matrix, ans, i, j, vis);
            if ((int)ans.size() == total) break;
            i++; // move to start of down

            goDown(matrix, ans, i, j, vis);
            if ((int)ans.size() == total) break;
            j--; // move to start of left

            goLeft(matrix, ans, i, j, vis);
            if ((int)ans.size() == total) break;
            i--; // move to start of up

            goUp(matrix, ans, i, j, vis);
            if ((int)ans.size() == total) break;
            j++; // move to start of right
        }

        return ans;
    }
};