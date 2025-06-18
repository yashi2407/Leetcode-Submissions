class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;
        int distanceCovered = startFuel;
        int stops = 0;
        int i = 0;
        int n = stations.size();

        while (distanceCovered < target) {
            // Push all reachable stations into the heap
            while (i < n && stations[i][0] <= distanceCovered) {
                maxHeap.push(stations[i][1]);
                i++;
            }

            if (maxHeap.empty()) return -1; // No station to refuel from

            // Refuel with the biggest fuel station we've passed
            distanceCovered += maxHeap.top();
            maxHeap.pop();
            stops++;
        }

        return stops;
    }
};
