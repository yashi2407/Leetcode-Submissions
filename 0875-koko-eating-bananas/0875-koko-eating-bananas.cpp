class Solution {
public:
    bool canEat(int currentSpeed, int h, vector<int>& piles){
        long long ans = 0;
        for(int i = 0;i<piles.size();i++){
            ans += ceil((double)piles[i]/currentSpeed);
        }
        if(ans<=h){
            return true;
        }
        return false;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if(canEat(mid,h,piles)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;

    }
};