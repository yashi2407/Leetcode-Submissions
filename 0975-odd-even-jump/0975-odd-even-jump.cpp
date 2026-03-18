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
        // even Jump
        for(int i=0;i<arr.size();i++){
            int nextIndex = -1; 
            int nextVal = INT_MIN;
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]>=arr[j]){
                    if(arr[j]>nextVal){
                        nextIndex = j;
                        nextVal = arr[j];
                    }
                }
            }
            evenJump[i] = nextIndex;
        }

        // TRY OUT EVERY START INDEX!
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            ans += jump(i,oddJump,evenJump,true,dp);
        }
        return ans;

    }
};