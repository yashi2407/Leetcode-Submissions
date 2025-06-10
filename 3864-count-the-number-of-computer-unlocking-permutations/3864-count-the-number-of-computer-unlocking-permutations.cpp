class Solution {
public:
    int MOD = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int rootComplexity = complexity[0];
        long long ans = 1;
        for(int i=1;i<complexity.size();i++){
            if(complexity[i]<=rootComplexity){
                return 0;
            }
            else{
                ans = ans *i;
                ans = ans%MOD;
            }
        }
        return ans;
    }
};