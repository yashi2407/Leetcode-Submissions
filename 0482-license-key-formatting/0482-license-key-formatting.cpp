class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int counter = k;
        string ans = "";
        for(int i=s.size()-1;i>=0;i--){
            char temp = s[i];
            if(s[i] == '-'){
                continue;
            }
            if(isalpha(temp)){
                temp = toupper(temp);
            }
            if(counter == 0){
                ans+= "-";
                counter = k;
            }
            ans +=temp;
            counter--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};