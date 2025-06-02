class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>leftPass(ratings.size(),1);
        vector<int>rightPass(ratings.size(),1);
        for(int i = 1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                leftPass[i]=leftPass[i-1]+1;
            }
        }
        for(int i = ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                rightPass[i] = rightPass[i+1]+1;
            }
        }
        int ans = 0;
        for(int i =0;i<ratings.size();i++){
            ans+=max(leftPass[i],rightPass[i]);
        }
        return ans;
    }
};