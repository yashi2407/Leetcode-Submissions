class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0); // count of each letter left in s
        for (char c : s) freq[c - 'a']++;

        string t = "";     // robot hand
        string result = ""; // final output on paper

        for (char c : s) {
            t += c;
            freq[c - 'a']--;  // we moved it out of s

            // Find the smallest remaining character in s
            char smallest = 'z' + 1;
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    smallest = 'a' + i;
                    break;
                }
            }

            // While t.back() is ≤ smallest left in s, write it to result
            while (!t.empty() && t.back() <= smallest) {
                result += t.back();
                t.pop_back();
            }
        }

        // Write remaining letters in t
        while (!t.empty()) {
            result += t.back();
            t.pop_back();
        }

        return result;
    }
};
