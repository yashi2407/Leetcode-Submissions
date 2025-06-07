class Solution {
public:
    string removeDuplicateLetters(string s) {
        // answer will be build in stack
        stack<char>st;
        vector<bool>vis(26,false);
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            mp[s[i]]--;
            if (vis[s[i] - 'a']) continue;
            while(!st.empty() && st.top()>s[i]&& mp[st.top()]>0){
                vis[st.top() - 'a']=false;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-'a']= true;
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