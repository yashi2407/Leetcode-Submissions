class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        long long currentOnes = 0;
        long long ans = 0;

        for (char c : s) {
            if (c == '1') {
                currentOnes++;
                ans = (ans + currentOnes) % MOD;  // each 1 extends all-1's substrings
            } else {
                currentOnes = 0;
            }
        }

        return (int)ans;
    }
};
