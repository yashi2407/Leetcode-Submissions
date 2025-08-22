class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec;
        for(int i=0;i<speed.size();i++){
            vec.push_back({position[i],speed[i]});
        }
        sort(vec.begin(),vec.end(), [](auto &a, auto &b){
            return a.first<b.first;
        });

        stack<double>st;
        for(int i=vec.size()-1;i>=0;i--){
            // is current car and the car at top of stack gonna collide and form a fleet?
            int currentCarSpeed = vec[i].second;
            int currentCarPosition = vec[i].first;
            double timeTaken = (double)(target- currentCarPosition)/currentCarSpeed;

            if(st.empty() || timeTaken > st.top()){
                st.push(timeTaken);
            }
        }
        return st.size();
    }
};