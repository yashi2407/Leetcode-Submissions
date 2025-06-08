class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int curr = 1;
        for (int i = 0; i < n; i++) {
            res.push_back(curr);
            if (curr * 10 <= n) {
                curr *= 10; // go to next depth
            } else if (curr % 10 != 9 && curr + 1 <= n) {
                curr += 1; // next sibling
            } else {
                // backtrack to find next sibling
               while ((curr / 10) % 10 == 9) curr /= 10;
                curr = curr / 10 + 1;
            }
        }
        return res;
    }
};