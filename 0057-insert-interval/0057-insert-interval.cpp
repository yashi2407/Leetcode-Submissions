class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();
        // insert all the intervals that are coming before the new interval
        // start time of new interval is less than end time of current interva;
        while(i<n && newInterval[0]>intervals[i][1]){
            result.push_back(intervals[i]);
            i++;
        }

        // overlapping
        // start time of new interval is less than equal to end time of current!
        vector<int> newInterval1 = newInterval;
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval1[0] = min(intervals[i][0],newInterval1[0]);
            newInterval1[1] = max(intervals[i][1],newInterval1[1]);
            i++;
        }
        result.push_back(newInterval1);

        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;

    }
};