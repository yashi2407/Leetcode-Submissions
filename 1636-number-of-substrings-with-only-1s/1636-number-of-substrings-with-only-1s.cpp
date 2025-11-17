class Solution {
public:
    int numSub(string s) {
        int MOD = 1e9+7;
        long long currentOnes = 0;
        long long ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                currentOnes++;
            }
            else {
                // cout<<"heree"<<currentOnes;
                ans += ((currentOnes *(currentOnes+1))/2)%MOD;
                currentOnes = 0;
            }
        }
        // if trailing 1's
        ans += ((currentOnes *(currentOnes+1))/2)%MOD;
        return (int)ans%MOD;
    }
};