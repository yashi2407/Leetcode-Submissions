class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int maxFreq=0;
        int i=0,j = 0;
        int ans = 0;
        // length - maxFrequency <=k
        while(j<s.size()){
            freq[s[j]-'A']++;
            maxFreq= max(maxFreq,freq[s[j]-'A']);
            // if conditions fails!
            while((j-i+1) - maxFreq > k){
                // remove the calculations of i to shrink the window to valid one!
                freq[s[i]-'A']--;
                maxFreq = 0;
                for(int i=0;i<26;i++){
                    maxFreq = max(maxFreq, freq[i]);
                }
                i++;
            }
            ans = max(ans, j-i+1);
            
            j++;
        }
        return ans;
    }
};