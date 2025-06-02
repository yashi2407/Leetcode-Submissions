class Solution {
public:
    int util(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, int index, vector<int>&dp){
        if(index >= profit.size()) {
            return 0;
        }
        // get the next jobs to be done and return the max profit from there.
        int nextIndex = lower_bound(startTime.begin(), startTime.end(), endTime[index]) - startTime.begin();
        if(dp[index]!=-1){
            return dp[index];
        }

        // Option 1: take the current job
        int doJob = profit[index] + util(startTime, endTime, profit, nextIndex,dp);
        // don't do the job
        int dontDo= util(startTime,endTime,profit,index+1,dp);
        return dp[index]= max(doJob,dontDo);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> jobs;
        for(int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        // Sort jobs by start time (or end time would also work)
        sort(jobs.begin(), jobs.end());

        for(int i = 0; i < n; i++) {
            tie(startTime[i], endTime[i], profit[i]) = jobs[i];
        }
        vector<int>dp(startTime.size()+1,-1);
        return util(startTime,endTime,profit,0,dp);
    }
};