class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long power = n;
        if(n<0){
            x=1/x;
            power = -power;
        }
        while(power>0){
            if(power%2==0){
                x = x*x;
                power=power/2;
            }
            else{
                ans = ans * x;
                power-=1;
            }
        }
        return ans;
    }
};