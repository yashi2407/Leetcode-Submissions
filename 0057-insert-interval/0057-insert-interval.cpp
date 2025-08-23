class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i=0;
        int n= intervals.size();
        // push non overlapping intervals!
        // if startTime of newInterval is greater that end time of i, we simply push the current interval in result!
        while(i<n && newInterval[0]>intervals[i][1]){
            result.push_back(intervals[i]);
            i++;
        }

        vector<int> newInterval1 = newInterval;
        // found the overlapping one!! we try to get the start time and end time of new Intervals.
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