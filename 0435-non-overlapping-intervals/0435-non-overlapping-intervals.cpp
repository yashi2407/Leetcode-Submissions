class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        int lastEndingTime = intervals[0][1]; 

        for(int i=1;i<intervals.size();i++){
            // check if we found any overlapping
            if(lastEndingTime > intervals[i][0]){
                ans++;
                // if ending time of the one in nonOverlapping array is more, remove it
                if(intervals[i][1]<lastEndingTime){
                    lastEndingTime = intervals[i][1];
                }
            }
            else {
                lastEndingTime = intervals[i][1];
            }
        }
        return ans;
    }
};