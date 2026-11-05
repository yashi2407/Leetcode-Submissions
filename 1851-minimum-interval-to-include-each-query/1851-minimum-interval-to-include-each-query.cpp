class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        // Store query value with original index
        vector<pair<int,int>> sortedQueries;
        for (int j = 0; j < queries.size(); j++) {
            sortedQueries.push_back({queries[j], j});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        int i = 0;
        int j = 0;
        vector<int> ans(queries.size(), -1);

        while (j < sortedQueries.size()) {
            int query = sortedQueries[j].first;
            int originalIndex = sortedQueries[j].second;
            while (i < intervals.size() && intervals[i][0] <= query) {
                int size = intervals[i][1] - intervals[i][0] + 1;
                minHeap.push({size, intervals[i][1]});
                i++;
            }


            while (!minHeap.empty() && minHeap.top().second < query) {
                cout<<"popping"<<minHeap.top().second<<endl;
                minHeap.pop();
            }


            if (!minHeap.empty()) {
                ans[originalIndex] = minHeap.top().first;
            }

            j++;
        }

        return ans;
    }
};