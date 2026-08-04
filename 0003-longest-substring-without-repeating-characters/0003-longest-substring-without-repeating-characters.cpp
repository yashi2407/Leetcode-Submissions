class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j=0;
        int ans = 0;
        unordered_map<char,int>mp;
        while(j<s.size()){
            // calculations of j
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            // correct window
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};