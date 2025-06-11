class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        vector<int> ans;
        int i=0,j=0;
        map<char,int>mp;
        for(int i = 0;i<p.size();i++){
            mp[p[i]]++;
        }
        int count = mp.size();
        while(j<s.size()){
            if(mp.find(s[j])!= mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                   count--;
                }
            }
            if(j-i+1 == k){
                if(count==0){
                    ans.push_back(i);
                }
                // revert calcualtions of i
                // if the current letter in p, the increase the count!
                if(mp.find(s[i])!= mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1){
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};