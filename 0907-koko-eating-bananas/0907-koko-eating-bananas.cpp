class Solution {
public:
    long long getHours(vector<int>& piles, int currentK){
        long long totalHours=0;
        for(int i =0;i<piles.size();i++){
            totalHours += (1LL * piles[i] + currentK - 1) / currentK; 
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int low = 1;
        int high = piles[piles.size()-1];
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(getHours(piles,mid)>h){
            // move to a greater k because we are taking more hours than expected
               low = mid+1;
            }
            else
            {
                ans = mid;
                // can try for lower k
                high = mid-1;
            }

        }
        return ans;
    }
};