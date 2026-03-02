class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> endZeros(n,0);
        for(int i=0;i<n;i++){
            int zeros = 0;
            for(int j = grid[0].size()-1;j>=0;j--){
                if(grid[i][j]== 0){
                    zeros++;
                }
                else{
                    break;
                }
            }
            endZeros[i] = zeros;
        }
        int ans = 0;
        // calculate the ans
        for(int i=0;i<n;i++){
            int zerosNeeded = n-i-1;
            if(zerosNeeded<=endZeros[i]){
                continue;
            }
            int k = i + 1;
            while (k < n && endZeros[k] < zerosNeeded){
                k++;
            }
            if (k == n) return -1;
            while (k > i) {
                swap(endZeros[k], endZeros[k - 1]);
                ans++;
                k--;
            }

        }
        return ans;
    }
};