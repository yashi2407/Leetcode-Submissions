
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
        long long covered = LLONG_MIN;

        while (j < newTargetIntervals.size()) {
            long long start = newTargetIntervals[j][0];
            long long end = newTargetIntervals[j][1];

            if (covered >= end) {
                j++;
                continue;
            }

            long long current = max(covered, start);
            long long maxReach = covered;

            while (i < availableIntervals.size() &&
                   availableIntervals[i][0] <= current) {
                maxReach = max(maxReach,
                               (long long)availableIntervals[i][1]);
                i++;
            }

            if (maxReach < current ||
                (covered >= start && maxReach <= covered))
                return -1;

            covered = maxReach;
            ans++;

            while (j < newTargetIntervals.size() &&
                   newTargetIntervals[j][1] <= covered) {
                j++;
            }
        }

        return ans;
    }
};
