class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && (st.back()>num[i] && k>0)){
                st.pop_back();
                k--;
            }
            st+=num[i];
        }
        while(k>0){
            st.pop_back();
            k--;
        }
        int i=0;
        while (i < st.size() && st[i] == '0') {
            i++;
        }
        string result = st.substr(i);
        return result.empty() ? "0" : result;
    }
};