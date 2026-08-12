class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,int>mp;
        for(int i = 0;i<p.size();i++){
            mp[p[i]]++;
        }
        int distinctCount = mp.size();
        int i=0;int j=0;
        while(j<s.size()){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    distinctCount--;
                }
            }
            // we hit the window size!
            if(j-i+1 == p.size()){
                if(distinctCount == 0){
                    ans.push_back(i);
                }
                // we hit thw window size, gotta reduce i
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1){
                        distinctCount++;
                    }
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};