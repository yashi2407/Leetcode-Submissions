class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(int i = 0;i<t.size();i++){
            mp[t[i]]++;
        }
        int count = mp.size();
        int i=0,j=0;
        int minLength = INT_MAX;
        int startIndex = 0;
        while(j<s.size()){
            // do calculations for j
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            // when we hit the count = 0, possible answer found
            while(count == 0){
                int currentLength = j - i + 1;
                if (currentLength < minLength) {
                    minLength = currentLength;
                    startIndex = i;  // <- capture start
                }
                // remove the calcualtions of i till count == 0
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]== 1){
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
        return (minLength == INT_MAX) ? "" : s.substr(startIndex, minLength);
    }
};