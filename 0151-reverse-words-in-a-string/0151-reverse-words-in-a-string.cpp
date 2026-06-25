class Solution {
public:
    string reverseWords(string s) {
        string current = "";
        string ans = "";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == ' '){
                if(current.size() != 0){
                    reverse(current.begin(),current.end());
                    ans = ans + current + " ";
                    current = "";
                }
            }
            else {
                current += s[i];
            }
        }
        if(current.size() != 0){
            reverse(current.begin(),current.end());
            ans = ans + current;
        }
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};