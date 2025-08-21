class Solution {
public:
    int solveOneDArray(vector<int> &arr){
        int ans=0,consecutive=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1){
                consecutive++;
            }
            else{
                consecutive=0;
            }
            ans+=consecutive;
        }
        return ans;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int row = mat.size();
        int n = mat[0].size();
        int total = 0;

        for(int startRow = 0; startRow<row; startRow++){
            vector<int>arr(n,1);
            for(int endRow = startRow; endRow<row; endRow++){
                // generate the 1d vector for each row
                for(int i=0;i<n;i++){
                    arr[i]= arr[i] && mat[endRow][i];
                }
                total += solveOneDArray(arr);
            }
        }
        return total;
    }
};