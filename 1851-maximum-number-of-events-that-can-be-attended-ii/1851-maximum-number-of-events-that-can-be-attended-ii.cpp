class Solution {
public:
    int findIndex(vector<vector<int>>& events, int index) {
        int endTime = events[index][1];
        int left = index + 1, right = events.size()-1, ans = events.size();
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // found one whose start is greater than ending
            if (events[mid][0] > endTime) {
                ans = min(ans,mid);
                right = mid-1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
    int util(vector<vector<int>>& events, int k, int index, vector<vector<int>>&dp){
        // base case
        if (index == events.size() || k == 0) return 0;
        // take it
        if(dp[index][k]!=-1){
            return dp[index][k];
        }
        int take=0,notTake=0;
        if(k>0){
            int nextIndex = findIndex(events,index);
            take = events[index][2] + util(events,k-1,nextIndex,dp);
        }
        notTake = util(events,k,index+1,dp);
        return dp[index][k] = max(take,notTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>>dp(events.size()+1, vector<int>(k+1,-1));
        return util(events,k,0,dp);
    }
};