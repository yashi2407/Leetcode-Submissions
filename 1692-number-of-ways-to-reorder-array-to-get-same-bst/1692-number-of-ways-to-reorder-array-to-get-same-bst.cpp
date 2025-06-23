const int MOD = 1e9 + 7;
class Solution {
public:
    const int maxNum = 1005;
    vector<long long> fact, invFact;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b % 2) res = res * a % MOD;
            a = a * a % MOD;
            b /= 2;
        }
        return res;
    }

    void precompute() {
        fact.resize(maxNum);
        invFact.resize(maxNum);
        fact[0] = invFact[0] = 1;
        for (int i = 1; i < maxNum; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            invFact[i] = modPow(fact[i], MOD - 2);  // Fermat's inverse
        }
    }

    long long C(int n, int k) {
        if (k > n) return 0;
        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    }

    int solve(vector<int>& nums){
        int n=nums.size();
        if (nums.empty() || nums.size() <= 2) return 1;
        // left side of the recursion would be elements smaller than current root
        // right side would be greater than current root
        int root = nums[0];
        vector<int>leftArray;
        vector<int>rightArray;
        for(int i=1;i<n;i++){
            if(nums[i]<root){
                leftArray.push_back(nums[i]);
            }
            else{
                rightArray.push_back(nums[i]);
            }
        }
        long long left = solve(leftArray) % MOD;
        long long right = solve(rightArray) % MOD;

        // now I have one root, l left and r right. I can place those l elements at any of the l+r(n-1 since root is fixed) places. Just relative order among them has to be maintained.
        long long ways = C(n-1,leftArray.size());

        return (((left*right)%MOD) * ways)%MOD;

    }
    int numOfWays(vector<int>& nums) {
        // solve gets the number of ways to solve 
        precompute();
        int ans = solve(nums);
        return (ans - 1);
    }
};