class Solution {
public:
    int util(string &s, int currentIndex, vector<int> &memo){
        if(currentIndex >= s.size()){
            return 1;
        }
        if(s[currentIndex] == '0'){
            return 0;
        }
        if(memo[currentIndex] != -1) {
            return memo[currentIndex];
        }
        int ans = util(s, currentIndex + 1, memo);
        if(currentIndex + 1 < s.size()){
            int twoDigitNum = stoi(s.substr(currentIndex, 2));
            if(twoDigitNum >= 1 && twoDigitNum <= 26) {
                ans += util(s, currentIndex + 2, memo);
            }
        }
        return memo[currentIndex] = ans;
    }
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return util(s,0,memo);
    }
};