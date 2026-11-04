
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            int lastEndTime = ans.back()[1];

            if (intervals[i][0] <= lastEndTime) {
                ans.back()[1] = max(lastEndTime, intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }

    int minSelection(vector<vector<int>>& availableIntervals,
                     vector<vector<int>>& targetIntervals) {

        if (targetIntervals.empty()) return 0;

        sort(availableIntervals.begin(), availableIntervals.end());

        vector<vector<int>> newTargetIntervals = merge(targetIntervals);

        int i = 0;
        int j = 0;
        int ans = 0;
        int current = newTargetIntervals[0][0];

        while (j < newTargetIntervals.size()) {
            int maxReach = -1;
            // let's move i first to get the max Reach!
            while(i<availableIntervals.size() && availableIntervals[i][0]<=current){
                maxReach = max(maxReach,availableIntervals[i][1]);
                i++;
            }
            if(maxReach == -1){
                return -1;
            }
            //[current,maxReach covered]
            while(j<newTargetIntervals.size() && newTargetIntervals[j][1]<=maxReach){
                j++;
            }
            ans++;
            if(j == newTargetIntervals.size()){
                return ans;
            }
            current = max(maxReach,newTargetIntervals[j][0]);
        }

        return ans;
    }
};
