class Solution {
public:
    unordered_set<string> result;
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                if (count == 0) return false;
                count--;
            }
        }
        return count == 0;
    }
    void dfs(string s, int index, int leftRemove, int rightRemove, unordered_set<string>& visited) {
        if (leftRemove == 0 && rightRemove == 0) {
            if (isValid(s)) {
                result.insert(s);
            }
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            // Skip duplicate removals
            if (i > index && s[i] == s[i - 1]) continue;

            // Only try to remove parentheses
            if (s[i] == '(' || s[i] == ')') {
                string temp = s;
                temp.erase(i, 1);

                if (s[i] == '(' && leftRemove > 0) {
                    if (visited.count(temp) == 0) {
                        visited.insert(temp);
                        dfs(temp, i, leftRemove - 1, rightRemove, visited);
                    }
                } else if (s[i] == ')' && rightRemove > 0) {
                    if (visited.count(temp) == 0) {
                        visited.insert(temp);
                        dfs(temp, i, leftRemove, rightRemove - 1, visited);
                    }
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0, rightRemove = 0;
        for (char c : s) {
            if (c == '(') leftRemove++;
            else if (c == ')') {
                if (leftRemove == 0) rightRemove++;
                else leftRemove--;
            }
        }
        unordered_set<string> visited;// kinda like dfs
        visited.insert(s);
        dfs(s, 0, leftRemove, rightRemove, visited);

        if (result.empty()) return {""};
        return vector<string>(result.begin(), result.end());
    }
};