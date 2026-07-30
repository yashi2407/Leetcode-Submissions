class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
                continue;
            }
            else if(s[i] == ')'){
                if(st.empty() || st.top()!= '('){
                    return false;
                }
            }
            else if(s[i] == ']'){
                if(st.empty() || st.top()!= '['){
                    return false;
                }
            }
            else if(s[i] == '}'){
                if(st.empty() || st.top()!= '{'){
                    return false;
                }
            }
            st.pop();
        }
        return st.empty() ? true : false;
    }
};