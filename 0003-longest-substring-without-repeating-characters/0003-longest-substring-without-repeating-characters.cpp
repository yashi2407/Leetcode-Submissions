class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0; int j=0;
        int ans = 0;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp[s[j]] == 1){
                ans = max(ans,j-i+1);
            }
            // if we have duplicates!
            while(mp[s[j]]!= 1){
                mp[s[i]]--;
                i++;
            }
            j++;

        }
        return ans;
    }
};