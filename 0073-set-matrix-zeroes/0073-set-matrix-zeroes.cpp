class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>locations;
        //O(mn)
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    locations.push_back({i,j});
                }
            }
        }
        unordered_set<int>rowsChanged;
        unordered_set<int>colChanged;

        // iterate over the loctions and set them
        for(int i=0;i<locations.size();i++){
            int row = locations[i].first;
            int col = locations[i].second;

            if(rowsChanged.find(row) == rowsChanged.end()){
                // change row zero
                for(int j = 0;j<matrix[0].size();j++){
                    matrix[row][j] = 0;
                }
                rowsChanged.insert(row);
            }
            if(colChanged.find(col) == colChanged.end()){
                // change col!!
                for(int j=0;j<matrix.size();j++){
                    matrix[j][col] = 0;
                }
                colChanged.insert(col);
            }
        }
    }
};