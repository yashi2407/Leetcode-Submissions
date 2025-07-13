class Solution {
public: 
    int M = 1e9+7;
    unordered_map<int,vector<int>>hatToPeople;

    int util(int peopleAssigned, int hat, int totalPeople, vector<vector<int>>&dp){
        if (peopleAssigned == (1 << totalPeople) - 1) return 1;  // all people assigned hats
        if (hat > 40) return 0;  // no more hats left

        if(dp[peopleAssigned][hat]!=-1){
            return dp[peopleAssigned][hat];
        }
        int ways = 0;
        // skip the hat
        ways = (ways + util(peopleAssigned,hat+1,totalPeople,dp)) % M;

        // assign this hat to a person who likes it and hasn't been assigned a hat yet!
        vector<int>interestedPeople = hatToPeople[hat];
        for(int i=0;i<interestedPeople.size();i++){
            if ((peopleAssigned & (1 << interestedPeople[i])) == 0){
                // we can assign this hat to this particlar person!
                int newMask = peopleAssigned | (1 << interestedPeople[i]);
                ways = (ways + util(newMask, hat + 1, totalPeople, dp)) % M;
            }
        }
        return dp[peopleAssigned][hat]= ways;

    }
    int numberWays(vector<vector<int>>& hats) {
        int totalPeople = hats.size();
        for(int i=0;i<hats.size();i++){
            for(int hat : hats[i]){
                // this hat is liked by ith person!
                hatToPeople[hat].push_back(i);
            }
        }
        int peopleAssigned = 0;
        vector<vector<int>> dp((1 << totalPeople), vector<int>(41, -1));
        return util(peopleAssigned,1,totalPeople,dp);
    }
};