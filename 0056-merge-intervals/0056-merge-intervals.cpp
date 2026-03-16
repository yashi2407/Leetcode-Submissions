class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(),[](const vector<int>&a, const vector<int>&b){
            return a[0]<b[0];
        });
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            //if they overlap
            if(ans[ans.size()-1][1]>=intervals[i][0]){
                // ans[ans.size()-1][0] = min(ans[ans.size()-1][0],intervals[i][0]);
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1],intervals[i][1]);

            }
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;

    }
};