class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<bool>used(words.size(),false);
        unordered_map<string, int> count;
        for (const string& word : words) {
            count[word]++;
        }
        int length = 0;
        bool hasCenter = false;

        // Go through each word in the map
        for (auto it = count.begin(); it != count.end(); ++it) {
            string word = it->first;
            int freq = it->second;

            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word != rev) {
                // Word and its reverse are different, like "ab" and "ba"
                if (count.find(rev) != count.end()) {
                    // ab ab ba --> we can form one pair only, hence min
                    int pairCount = min(freq, count[rev]);
                    length += pairCount * 4;
                    // Reduce their counts so we don't count them again
                    count[word] -= pairCount;
                    count[rev] -= pairCount;
                }
            } else {
                // Word is the same as its reverse, like "gg"
                length += (freq / 2) * 4;
                if (freq % 2 == 1) {
                    hasCenter = true;
                }
            }
        }

        // If we had one extra "gg" or similar, put it in center
        if (hasCenter) {
            length += 2;
        }
        return length;
    }
};