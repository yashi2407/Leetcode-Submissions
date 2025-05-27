class Solution {
public:
    int util(int i,int j, string word1, string word2,vector<vector<int>>&dp){
        // Base condition
        // we completed word 1, so we need to insert remaining characters from word2
        if(i==word1.size()){
            return word2.length() - j;
        }
        if(j==word2.size()){
            // delete the remaining characters from word1
            return word1.length() - i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // if current index equal don't do anything
        if(word1[i]==word2[j]){
            return dp[i][j]= util(i+1,j+1,word1,word2,dp);
        }
        else {
            // insert , delete , replace
            return dp[i][j] = 1 + std::min(
                util(i, j + 1, word1, word2,dp),     // INSERT
                min(util(i + 1, j, word1, word2,dp),     // DELETE
                util(i + 1, j + 1, word1, word2,dp))  // REPLACE
            );
        }
    }
    int minDistance(string word1, string word2) {
        int i =0,j=0;
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return util(i,j,word1,word2,dp);
    }
};