class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int i=0,j=0; // i-> traverse pushed and j to traverse popped
        while(i<pushed.size()){
            // push pushed[i]
            st.push(pushed[i]);
            i++;
            while(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
            
        }
        return (j == popped.size()) ? true : false;
    }
};