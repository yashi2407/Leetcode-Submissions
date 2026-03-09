class Solution {
public:
    static const int MOD = 1e9 + 7;
    int dp[201][201][2];

    int util(int zero, int one, int limit, bool lastOne) {
        if (zero == 0 && one == 0) {
            return 1;
        }

        if (dp[zero][one][lastOne] != -1) {
            return dp[zero][one][lastOne];
        }

        long long result = 0;

        if (lastOne == true) {
            // now place zeros
            for (int i = 1; i <= min(zero, limit); i++) {
                result = (result + util(zero - i, one, limit, false)) % MOD;
            }
        } else {
            // now place ones
            for (int i = 1; i <= min(one, limit); i++) {
                result = (result + util(zero, one - i, limit, true)) % MOD;
            }
        }

        return dp[zero][one][lastOne] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));
        return (util(zero, one, limit, false) + util(zero, one, limit, true)) % MOD;
    }
};