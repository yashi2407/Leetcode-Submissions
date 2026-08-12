class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        unordered_set<int>indexToSkip;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                // open bracket at i index!
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty()){
                    // gotta skip the index
                    indexToSkip.insert(i);
                }
                else {
                    st.pop();
                }
            }
        }
        // take out all open brackets that we need to remove
        while(!st.empty()){
            indexToSkip.insert(st.top());
            st.pop();
        }
        for(int i=0;i<s.size();i++){
            if(indexToSkip.find(i) == indexToSkip.end()){
                ans+= s[i];
            }
        }
        return ans;
    }
};