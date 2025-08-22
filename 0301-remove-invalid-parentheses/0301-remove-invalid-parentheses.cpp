class Solution {
public:
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
    void util(unordered_set<string> &visited, vector<string> &ans, string s, int leftRemove, int rightRemove, int index){
        if (leftRemove == 0 && rightRemove == 0) {
            if (isValid(s)) {
                ans.push_back(s);
            }
            return;
        }

        // try out all possible conditions!
        for(int i=index;i<s.size();i++){
            if (i > index && s[i] == s[i - 1]) continue;
            if (s[i] == '(' || s[i] == ')') {
                string temp = s;
                temp.erase(i, 1);

                if (s[i] == '(' && leftRemove > 0) {
                    if (visited.count(temp) == 0) {
                        visited.insert(temp);
                        util(visited, ans, temp, leftRemove-1, rightRemove, i);
                    }
                } else if (s[i] == ')' && rightRemove > 0) {
                    if (visited.count(temp) == 0) {
                        visited.insert(temp);
                        util(visited, ans, temp, leftRemove, rightRemove - 1, i);
                    }
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        // first figure out how many open and close we need to remove
        int leftRemove = 0, rightRemove = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]== '('){
                leftRemove++;
            }
            else if(s[i] == ')'){
                if(leftRemove>0){
                    leftRemove--;
                }
                else{
                    rightRemove++;
                }
            }

        }
        unordered_set<string> visited;
        vector<string> ans;
        util(visited,ans,s,leftRemove,rightRemove, 0);
        return ans;
        
    }
};