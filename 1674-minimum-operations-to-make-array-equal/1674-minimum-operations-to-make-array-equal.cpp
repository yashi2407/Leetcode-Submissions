class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        vector<int>arr(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            arr[i]= (2 * i) + 1;
            sum+=arr[i];
        }
        int target = sum/n;
        for(int i=0;i<n/2;i++){
            if(arr[i]!=target){
                ans+= abs(arr[i]-target);
            }
        }
        return ans;
    }
};