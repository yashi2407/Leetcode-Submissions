class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int>meetingRooms(n,0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>,greater<pair<long long,int>>> heap;
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>,greater<int>> availableRooms;
        for(int i=0;i<n;i++){
            availableRooms.push(i);
        }
        for(int i=0;i<meetings.size();i++){
            // clean up the availability!
            while(!heap.empty() && heap.top().first <= meetings[i][0]){
                int freedRoom = heap.top().second;
                heap.pop(); 
                availableRooms.push(freedRoom);
            }
            // if room is available!
            if(!availableRooms.empty()){
                int meetingRoom = availableRooms.top();
                availableRooms.pop();
                meetingRooms[meetingRoom]++;
                heap.push({meetings[i][1],meetingRoom});
            }
            // delay the meeting!
            else {
                int duration = meetings[i][1]- meetings[i][0];
                long long newEndTime = heap.top().first + duration;
                int room = heap.top().second;
                heap.pop();
                meetingRooms[room]++;
                heap.push({newEndTime,room});
            }
        }
        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (meetingRooms[i] > maxMeetings) {
                maxMeetings = meetingRooms[i];
                resultRoom = i;
            }
        }
        return resultRoom;
    }
};