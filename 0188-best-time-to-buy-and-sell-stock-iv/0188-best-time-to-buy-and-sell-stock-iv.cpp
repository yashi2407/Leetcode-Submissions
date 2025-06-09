class Solution {
public:
    int util(vector<int>& prices,int k, int state , int index,vector<vector<vector<int>>> &dp){
        // base condition
        if (index == prices.size() || k == 0) return 0;

        if(dp[index][state][k]!=-1){
            return dp[index][state][k];
        }
        // if state is zero, i can either start the transcation or do nothing.
        int ans = 0;
        if(state == 0){
            // start transation if k allows
            if(k>0){
                ans = max(ans, -prices[index] + util(prices, k, 1, index + 1,dp));
            }
            // or don't do anything
            ans=max(ans,util(prices,k,state,index+1,dp));
        }
        if(state == 1){
            // we don't do anything at this index or we sell it
            // don't do anythign
            ans=max(ans,util(prices,k,state,index+1,dp));
            /// sell it
            ans=max(ans,prices[index] + util(prices,k-1,0,index+1,dp));
        }
        return dp[index][state][k]= ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size()+1;
        // index, state , k
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // 0 means I have't statred any transaction yet and next zero is the index upon which i am deciding currently
        return util(prices,k,0,0,dp);
    }
};