class Solution {
public:
    bool isPalindrome(string &s, int i, int j, vector<vector<int>>&isPalindromTable){
        // Base cases for short strings
        if (i >= j) return true;
        
        // If already computed, return the cached result
        if (isPalindromTable[i][j] != -1) {
            return isPalindromTable[i][j];
        }
        
        // A string is a palindrome if edge characters match AND the inside matches
        if (s[i] == s[j]) {
            isPalindromTable[i][j] = isPalindrome(s, i + 1, j - 1, isPalindromTable);
        } else {
            isPalindromTable[i][j] = 0; // false
        }
        
        return isPalindromTable[i][j];
    }
    string longestPalindrome(string s) {
        string ans = "";
        vector<vector<int>>isPalindromTable(s.size(),vector<int>(s.size(),-1));
        for(int i = s.size()-1; i>=0;i--){
            for(int j = i;j<s.size();j++){
                if(i == j){
                    isPalindromTable[i][j] = true;
                }
                if(isPalindrome(s,i,j,isPalindromTable)){
                    if(j-i+1 > ans.size()){
                        ans = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};