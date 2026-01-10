class Solution {
public:
    int dp[1001][1001];
    int solve(string &s1, string &s2, int n, int m){
        if(n < 0 || m < 0){
            // delete all the characters of the string which is not zero!
            if(n < 0){
                int sum = 0;
                for (int k = 0; k <=m; k++) {
                    sum += (int)s2[k];
                }
                return sum;
            }
            else if(m < 0){
                // remove all characters of s1
                int sum = 0;
                for (int k = 0; k <=n; k++) {
                    sum += (int)s1[k];
                }
                return sum;
            }
            else {
                return 0;
            }
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        int ans = 0;
        // of characters same, we dont have to remove anything!
        if(s1[n]==s2[m]){
            ans = solve(s1,s2,n-1,m-1);
        }
        else{
            // remove last character ne by one from both!
            int choice1 = s1[n] + solve(s1,s2,n-1,m);
            int choice2 = s2[m] + solve(s1,s2,n,m-1);
            ans = min(choice1, choice2);
        }
        return dp[n][m] = ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        memset(dp, -1, sizeof(dp));
        return solve(s1,s2,n-1,m-1);
    }
};