class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>LPS(n,0);
        int current = 1;
        int prev = 0;
        while(current<n){
            if(s[current] == s[prev]){
                LPS[current] = prev+1;
                current++;
                prev++;
            }
            else{
                if(prev==0){
                    LPS[current]=0;
                    current++;
                }
                else{
                    prev=LPS[prev-1];
                }
            }
        }
        return s.substr(0,LPS[n-1]);
    }
};