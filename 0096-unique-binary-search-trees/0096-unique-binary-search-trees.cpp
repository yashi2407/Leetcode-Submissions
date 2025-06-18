class Solution {
public:
    int util(int n){
        if(n == 0 || n == 1){
            return 1;
        }
        // from 1->n, each van be root node 
        int total = 0;
        for(int i=1;i<=n;i++){
            int left = i-1;
            int right = n-i;
            total += util(left) * util(right);
        }
        return total;
    }
    int numTrees(int n) {
        return util(n);
    }
};