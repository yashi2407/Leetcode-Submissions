class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxFreqCount = count(freq.begin(), freq.end(), maxFreq);

        int part1 = (maxFreq - 1) * (n + 1) + maxFreqCount;
        return max((int)tasks.size(), part1);
    }
};