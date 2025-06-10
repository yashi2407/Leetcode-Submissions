class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i] - 'a']++;
        }
        int ans = INT_MIN;
        for (int i = 0; i < freq.size() - 1; i++) {
            for (int j = i + 1; j < freq.size(); j++) {
                if (freq[i] != 0 && freq[j] != 0) {
                    // Case 1: i is a1 (odd), j is a2 (even)
                    if (freq[i] % 2 != 0 && freq[j] % 2 == 0) {
                        ans = max(ans, freq[i] - freq[j]);
                    }

                    // Case 2: j is a1 (odd), i is a2 (even) — ULTA!
                    if (freq[j] % 2 != 0 && freq[i] % 2 == 0) {
                        ans = max(ans, freq[j] - freq[i]);
                    }
                }
            }
        }
        return ans == INT_MIN ? -1 : ans;
    }
};