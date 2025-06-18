class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        int i=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == ']'){
                // will do something
                // first get the string
                string temp="";
                while(st.top()!='['){
                    temp+=st.top();
                    st.pop();
                }
                st.pop(); // for ']'
                // now get the number till which we have to repeat
                string number = "";
                while(!st.empty() && isdigit(st.top())){
                    number+=st.top();
                    st.pop();
                }
                reverse(number.begin(),number.end());
                int num = stoi(number);
                string newString = "";
                for(int i=1;i<=num;i++){
                    newString+=temp;
                }
                // put in stack from back!
                for(int j = newString.size() - 1; j >= 0; j--){
                    st.push(newString[j]);
                }

            }
            else{
                st.push(s[i]);
            }
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};