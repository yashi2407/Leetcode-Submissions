class Solution {
public:
    // This function finds the max subarray sum <= k in a 1D array
    int lowerBoundIndex(vector<int>& row, int k) {
        set<int> prefixSums;
        prefixSums.insert(0);

        int currSum = 0;
        int maxSum = INT_MIN;

        for (int val : row) {
            currSum += val;

            // We want smallest prefixSum >= currSum - k
            auto it = prefixSums.lower_bound(currSum - k);
            if (it != prefixSums.end()) {
                maxSum = max(maxSum, currSum - *it);
            }

            prefixSums.insert(currSum);
        }

        return maxSum;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxAnswer = INT_MIN;

        for (int top = 0; top < m; ++top) {
            vector<int> colSum(n, 0);

            for (int bottom = top; bottom < m; ++bottom) {
                // Add current row to colSum
                for (int col = 0; col < n; ++col) {
                    colSum[col] += matrix[bottom][col];
                }

                // Now colSum represents 1D array for current row range
                maxAnswer = max(maxAnswer, lowerBoundIndex(colSum, k));
            }
        }

        return maxAnswer;
    }
};
