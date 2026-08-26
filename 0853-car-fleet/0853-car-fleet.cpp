class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>vec;
        for(int i=0;i<position.size();i++){
            vec.push_back({position[i],speed[i]});
        }
        sort(vec.begin(),vec.end(),[](pair<int,int>&a, pair<int,int>&b){
            return a.first<b.first;
        });
        vector<double>time(position.size());
        for(int i=0;i<position.size();i++){
            int currentCarSpeed = vec[i].second;
            int currentCarPosition = vec[i].first;
            double timeTaken = (double)(target - currentCarPosition)/currentCarSpeed;
            time[i] = timeTaken;
        }
        double currentFleetTime = time[time.size()-1];
        int fleetSize = 1;
        for(int i=time.size()-2;i>=0;i--){
            if(time[i]>currentFleetTime){
                fleetSize++;
                currentFleetTime = time[i];
            }
        }

        return fleetSize; 
    }
};