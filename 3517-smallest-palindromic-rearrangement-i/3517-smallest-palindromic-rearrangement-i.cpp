class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mp;
        for(auto it : s){
            mp[it]++;
        }
        string ans= "";
        char lastChar =' ';
        for(auto it : mp){
            char c = it.first;
            int freq = it.second;
            if(freq%2 !=0){
                lastChar = c;
            }
            int count = freq/2;
            for(int i=0;i<count;i++){
                ans+=c;
            }
        }
        string temp2 = ans;
        reverse(temp2.begin(),temp2.end());
        if(lastChar != ' '){
            ans = ans + lastChar + temp2;
            return ans;
        }
        ans = ans + temp2;
        
        return ans;

    }
};