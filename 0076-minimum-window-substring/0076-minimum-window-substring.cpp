class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        for(int i = 0;i<t.size();i++){
            mp[t[i]]++;
        }
        int count = mp.size(), i = 0,j=0;
        string ans = "";
        int minLen = INT_MAX;
        int startIndex = 0;
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if (mp[s[j]] == 0) count--;
            }
            // start removing to optimize the string
            while(count == 0){
                int currentLength = j-i+1;
                if(currentLength<minLen){
                    // possible candidate
                    minLen = j - i + 1;
                    startIndex = i;
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        count++;
                    }
                }
                i++;
            }
            j++;
            
        }
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};