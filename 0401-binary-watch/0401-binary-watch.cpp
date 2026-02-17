class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        if(turnedOn >=9){
            return ans;
        }
        for(int hours = 0; hours<=11;hours++){
            for(int mins = 0; mins<=59; mins++){
                if(__builtin_popcount(hours) + __builtin_popcount(mins) == turnedOn){
                        // format any is HH:MM
                        string tempAns = to_string(hours)+ ":";
                        string tempMins = to_string(mins);
                        if(mins<=9){
                            tempMins.insert(tempMins.begin()+ 0,'0');
                        }
                        tempAns +=tempMins;
                        ans.push_back(tempAns);
                }
            }
        }
        return ans;
    }
};