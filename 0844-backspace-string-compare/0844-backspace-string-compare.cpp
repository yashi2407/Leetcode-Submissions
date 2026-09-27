class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        for(int i = 0;i<s.size();i++){
            if(s[i]!= '#'){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        string version1 = "";
        while(!st.empty()){
            version1+=st.top();
            st.pop();
        }
        // same for t
        for(int i = 0;i<t.size();i++){
            if(t[i]!= '#'){
                st.push(t[i]);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        string version2 = "";
        while(!st.empty()){
            version2+=st.top();
            st.pop();
        }
        return version1 == version2;
    }
};