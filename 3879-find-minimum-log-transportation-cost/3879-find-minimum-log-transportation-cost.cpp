class Solution {
public:
    long long minCost(int n,int k){
        long long minCost = LLONG_MAX;
        for(long long i = 1;i<=n/2;i++){
            long long firstHalf = i;
            long long secondHalf = n-i;
            if(firstHalf<=k && secondHalf<=k){
                minCost = min(minCost,firstHalf*secondHalf);
            }
        }
        return minCost;
    }
    long long minCuttingCost(int n, int m, int k) {
        long long totalCost = 0;
        if(n>k){
            // n needs to be cut into two;
            totalCost=minCost(n,k);
        }
        else if(m>k){
            //m needs to be broken up 
            totalCost=minCost(m,k);
        }
        return totalCost;
    }
};