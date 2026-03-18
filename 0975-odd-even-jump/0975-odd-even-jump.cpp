class Solution {
public:
    int jump(int currentIndex, vector<int>&oddJump, vector<int>&evenJump, bool isOddJump, vector<vector<int>>&dp) {
        if(currentIndex >= oddJump.size()-1){
            return 1;
        }
        if(dp[currentIndex][isOddJump]!=-1){
            return dp[currentIndex][isOddJump];
        }

        int ans = 0;
        // if odd jump, goto next Index
        if(isOddJump){
            if(oddJump[currentIndex] == -1){
                return 0;// cant' jump further!
            }
            else {
                ans += jump(oddJump[currentIndex],oddJump,evenJump,false,dp);
            }
            
        }
        else {
            if(evenJump[currentIndex] == -1){
                return 0;// cant' jump further!
            }
            else{
                ans += jump(evenJump[currentIndex],oddJump,evenJump,true,dp);
            }
        }
        return dp[currentIndex][isOddJump] = ans;
    }
    int oddEvenJumps(vector<int>& arr) {
        vector<int> oddJump(arr.size(),-1);
        vector<int> evenJump(arr.size(),-1);
        vector<vector<int>>dp(arr.size()+1,vector<int>(2,-1));

        vector<int> idx(arr.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(),[&arr](int a, int b){
            if (arr[a] == arr[b]) return a<b;
            else return arr[a]<arr[b];
        });
        stack<int>st;
        for(int i = idx.size()-1;i>=0;i--){
            while(!st.empty() && idx[i]>st.top()){
                st.pop();
            }
            if(!st.empty()){
                oddJump[idx[i]] = st.top();
            }
            st.push(idx[i]);
        }

        vector<int> idx2(arr.size());
        iota(idx2.begin(), idx2.end(), 0);
        sort(idx2.begin(), idx2.end(),[&arr](int a, int b){
            if (arr[a] == arr[b]) return a<b;
            else return arr[a]>arr[b];
        });
        stack<int>st1;
        for(int i = idx2.size()-1;i>=0;i--){
            while(!st1.empty() && idx2[i]>st1.top()){
                st1.pop();
            }
            if(!st1.empty()){
                evenJump[idx2[i]] = st1.top();
            }
            st1.push(idx2[i]);
        }
        

        // TRY OUT EVERY START INDEX!
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            ans += jump(i,oddJump,evenJump,true,dp);
        }
        return ans;

    }
};