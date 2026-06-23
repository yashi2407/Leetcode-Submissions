class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalFuelNeeded = 0;
        int currentFuel = 0;
        int start = 0;
        for(int i=0;i<gas.size();i++){
            int diff = gas[i] - cost[i];
            totalFuelNeeded = totalFuelNeeded + diff;
            currentFuel = currentFuel + diff;
            if(currentFuel<0){
                currentFuel=0;
                start = i+1;
            }
        }
        // if total gas is less than total cost, no solution exists
        if (totalFuelNeeded < 0) {
            return -1;
        }

        return start;
    }
};