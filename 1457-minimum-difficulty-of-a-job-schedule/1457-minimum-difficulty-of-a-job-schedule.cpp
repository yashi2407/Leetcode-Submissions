class Solution {
public:
    int util(vector<int>& jobDifficulty, int d,int index, vector<vector<int>>&dp){
        if (d == 0 && index == jobDifficulty.size()) return 0;
        if (d == 0 || index == jobDifficulty.size()) return INT_MAX;
        if(dp[d][index]!=-1){
            return dp[d][index];
        }
        // assigning the jobs from index to n to the current day
        int ans = INT_MAX;;
        int maxDifficulty = INT_MIN;
        for(int i=index;i<=jobDifficulty.size()-d;i++){
            maxDifficulty = max(maxDifficulty,jobDifficulty[i]);
            int next = util(jobDifficulty,d-1,i+1,dp);
            if(next != INT_MAX){
                ans = min(ans, maxDifficulty + next);   
            }
        }
        return dp[d][index]= ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) return -1;
        vector<vector<int>>dp(d+1,vector<int>(jobDifficulty.size()+1,-1));
        int result = util(jobDifficulty, d, 0,dp);
        return result == INT_MAX ? -1 : result;
    }
};