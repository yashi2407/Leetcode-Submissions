class Solution {
public:
    string ans = "";
    bool util(int n , int &k , vector<bool>&used,int index,string currentPermutation){
        if(n==index){
            k--;
            if(k==0){
                ans= currentPermutation;
                return true;
            }
            return false;
        }
        for(int i =1;i<=n;i++){
            if(!used[i]){
                currentPermutation+= to_string(i);
                used[i]=true;
                if(util(n,k,used,index+1,currentPermutation)){
                    return true;
                }
                currentPermutation.pop_back();
                used[i]=false;
            }
        }
        return false;
    }
    string getPermutation(int n, int k) {
        vector<bool>used(n+1,false);
        util(n,k,used,0,"");
        return ans;
    }
};