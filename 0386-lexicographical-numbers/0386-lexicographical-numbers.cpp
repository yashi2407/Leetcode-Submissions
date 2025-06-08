class Solution {
public:
    void util(int n , vector<int>&ans,int current){
        if(current>n){
            return;
        }
        ans.push_back(current);
        for(int i=0;i<=9;i++){
            util(n,ans,current*10+i);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i =1;i<=9;i++){
            util(n,ans,i);
        }
        return ans;
    }
};