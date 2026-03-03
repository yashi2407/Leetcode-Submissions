class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int,int>mp;
        for(int i=0;i<s1.size();i++){
            mp[s1[i]]++;
        }
        int countDistinct = mp.size();
        int i = 0;
        int j = 0;
        while(j<s2.size()){
            // calculaitions of j.
            if(mp.find(s2[j])!= mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]] == 0){
                    countDistinct--;
                }
            }
            // window to big, shrink it
            if(j-i+1 > s1.size()) {
                if(mp.find(s2[i])!= mp.end()){
                    mp[s2[i]]++;
                    if(mp[s2[i]] == 1){
                        countDistinct++;
                    }
                }
                i++;
            }
            // we hit the window size, get the answer
            if(j-i+1 == s1.size()){
                if(countDistinct == 0){
                    return true;
                }
            }
            j++;
        }
        return false;
    }
};