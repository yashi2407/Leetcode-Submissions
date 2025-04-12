class Solution {
public:
    int getDays(vector<int>& weights, int capacity){
        int days = 1,currentCapacity = 0;
        for(int i =0;i<weights.size();i++){
            if(weights[i]+currentCapacity<=capacity){
                // we can add the weight[i] to the ship
                currentCapacity = currentCapacity + weights[i];
            }
            else {
                days++;
                currentCapacity = weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        int ans = -1;
        for(int i =0;i<weights.size();i++){
            high = high + weights[i];
        }
        while(low<=high){
            int mid = (low+high)/2;
            int currentDays = getDays(weights,mid);
            // we are getting more days, need to increase the capacity
            if(currentDays>days){
                low = mid+1;
            }
            else {
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};