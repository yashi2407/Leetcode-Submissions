class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        int i=0;
        while(i!=s.size()){
            if(s[i]!= ']'){
                st.push(s[i]);
                i++;
            }
            else {
                string toRepeat = "";
                while(st.top()!= '['){
                    toRepeat += st.top();
                    st.pop();                
                }
                reverse(toRepeat.begin(), toRepeat.end());
                st.pop();
                // now get how many times to repeat!
                string repeatNum = "";
                while(!st.empty() && isdigit(st.top())){
                    repeatNum+=st.top();
                    st.pop();
                }
                reverse(repeatNum.begin(),repeatNum.end());
                string tempString = "";
                for(int i=0;i<stoi(repeatNum);i++){
                    tempString+=toRepeat;
                }
                for (char ch : tempString) {
                    st.push(ch);
                }
                i++;
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};