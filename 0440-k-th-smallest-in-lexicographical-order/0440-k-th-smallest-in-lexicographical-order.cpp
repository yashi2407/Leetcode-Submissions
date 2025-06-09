class Solution {
public:
    long countSteps(int n, long first, long last) {
        long steps = 0;
        while (first <= n) {
            steps += min(n + 1L, last) - first;
            first *= 10;
            last *= 10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        long curr = 1;
        k -= 1; // We already consider 1 as the first number
        while (k > 0) {
            long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                // Skip this whole subtree
                curr += 1;
                k -= steps;
            } else {
                // Go deeper into the subtree
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};