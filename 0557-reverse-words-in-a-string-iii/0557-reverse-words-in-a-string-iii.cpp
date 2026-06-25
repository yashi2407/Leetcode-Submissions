class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string current = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                reverse(current.begin(),current.end());
                ans+=current + " ";
                current = "";
            }
            else {
                current+=s[i];
            }
        }
        reverse(current.begin(),current.end());
        ans+=current;
        return ans;
    }
};