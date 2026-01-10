class Solution {
public:
    int dp[1001][1001];
    int solve(string &s1, string &s2, int n, int m){
        if(n < 0 || m < 0){
            // delete all the characters of the string which is not zero!
            if(n < 0){
                return m+1;
            }
            else if(m < 0){
                // remove all characters of s1
                return n+1;
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
        if(s1[n] == s2[m]){
            ans = solve(s1,s2,n-1,m-1);
        }
        else{
            // remove last character one by one from both!
            int choice1 = 1 + solve(s1,s2,n-1,m);
            int choice2 = 1 + solve(s1,s2,n,m-1);
            ans = min(choice1, choice2);
        }
        return dp[n][m] = ans;
    }
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        memset(dp, -1, sizeof(dp));
        return solve(s1,s2,n-1,m-1);
    }
};