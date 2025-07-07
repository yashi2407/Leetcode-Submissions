class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n = events.size();
        int currentDay = events[0][0];
        int lastDay=0;
        for (auto& event : events){
            lastDay = max(lastDay, event[1]);
        }
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int i=0;
        int ans=0;
        while(currentDay<=lastDay){
            while (i < n && events[i][0] == currentDay) {
                minHeap.push(events[i][1]); // push end day
                i++;
            }
            // complete the task with min endind day
            while (!minHeap.empty() && minHeap.top() < currentDay) {
                minHeap.pop();
            }
            if (!minHeap.empty()) {
                minHeap.pop(); // attend
                ans++;
            }
            currentDay++;

        }
        return ans;
    }
};