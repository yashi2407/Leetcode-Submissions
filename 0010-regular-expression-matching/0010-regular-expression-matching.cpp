class Solution {
public:
    unordered_map<string, bool> memo;

    bool util(int i, int j, string& s, string& p) {
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];

        if (i == s.length() && j == p.length()) return memo[key] = true;
        if (j == p.length()) return memo[key] = false;

        bool match = (i < s.length()) && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.length() && p[j + 1] == '*') {
            // Try zero occurrences or one (if match)
            return memo[key] = util(i, j + 2, s, p) || (match && util(i + 1, j, s, p));
        }

        if (match) {
            return memo[key] = util(i + 1, j + 1, s, p);
        }

        return memo[key] = false;
    }

    bool isMatch(string s, string p) {
        return util(0, 0, s, p);
    }
};
