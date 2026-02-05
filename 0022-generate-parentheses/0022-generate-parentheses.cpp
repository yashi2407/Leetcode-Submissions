class Solution {
public:
    void util(vector<string>&ans, int open, int close, int n, string &current){
        if (open == n && close == n) {
            ans.push_back(current);
            return;
        }

        if (open < n) {
            current.push_back('(');
            util(ans, open + 1, close, n, current);
            current.pop_back();
        }

        if (close < open) {
            current.push_back(')');
            util(ans, open, close + 1, n, current);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = 0; int close = 0;
        string current = "";
        util(ans,open,close,n,current);
        return ans;
    }
};