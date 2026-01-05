class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int countNegative = 0;
        int smallestNegative = INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                ans += abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    countNegative++;
                }
                smallestNegative = min(smallestNegative, abs(matrix[i][j]));
            }
        }
        if(countNegative%2 == 0){
            return ans;
        }
        return ans - 2LL * smallestNegative;
    }
};