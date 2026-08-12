class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int openCounter = 0;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                openCounter++;
                ans += s[i];
            }
            else if(s[i] == ')'){
                if(openCounter > 0){
                    openCounter--;
                    ans += s[i];
                }
            }
            else {
                ans += s[i];
            }
        }
        if(openCounter == 0){
            return ans;
        }
        string finalAns = "";
        if(openCounter>0){
            for(int i = ans.size()-1;i>=0;i--){
                if(ans[i] == '(' && openCounter>0){
                    openCounter--;
                }
                else {
                    finalAns += ans[i];
                }
            }
        }
        reverse(finalAns.begin(), finalAns.end());
        return finalAns;
    }
};