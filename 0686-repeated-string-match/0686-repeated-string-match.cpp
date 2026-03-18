class Solution {
public:
bool isSubstring(string a, string b) {
    return a.find(b) != string::npos;
}
string repeatString(string s, int times) {
    string result = "";

    for (int i = 0; i < times; i++) {
        result += s;
    }

    return result;
}
int repeatedStringMatch(string a, string b) {
        if (isSubstring(a, b)) {
            return 1;
        }
        int mn = b.size()/a.size();
        // int mn = (b.size() + a.size() - 1) / a.size();
        for (int i = mn; i <= mn + 5; i++) {
            string repeated = repeatString(a, i);
            if (isSubstring(repeated, b)) {
                return i;
            }
        }
        return -1;
    }
};