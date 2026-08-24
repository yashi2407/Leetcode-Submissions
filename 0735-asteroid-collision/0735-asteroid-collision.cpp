class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<asteroids.size();i++){
            bool add = true;
            if(asteroids[i]<0){
                while(!st.empty() && st.top()>0){
                    int ast1 = asteroids[i];
                    int ast2 = st.top();
                    if(abs(ast1)>ast2){
                        st.pop();
                    }
                    else if(abs(ast1)<ast2){
                        add = false;
                        break;
                    }
                    else {
                        st.pop();
                        add = false;
                        break;
                    }
                }
            }
            if(add){
                st.push(asteroids[i]);
            }
           
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};