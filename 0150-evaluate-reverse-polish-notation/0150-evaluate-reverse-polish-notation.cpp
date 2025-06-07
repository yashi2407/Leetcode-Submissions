class Solution {
public:
    int solve(string op, int num1, int num2){
        if (op == "+") return num1 + num2;
        if (op == "-") return num1 - num2;
        if (op == "*") return num1 * num2;
        return num1 / num2;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int res = 0;
        for(int i = 0;i<tokens.size();i++){
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(solve(tokens[i],num2,num1));
            }
            else{
                st.push(stoi(tokens[i]));
            }
        } 
        return st.top();
    }
};