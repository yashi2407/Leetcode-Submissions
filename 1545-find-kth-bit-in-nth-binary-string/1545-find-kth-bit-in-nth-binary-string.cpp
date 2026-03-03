class Solution {
public:
    char findKthBit(int n, int k) {
        //s[i] is stores at i-1 index
        vector<string> vec(n);
        vec[0] = "0";
        for(int i=1;i<n;i++){
            string bits = vec[i-1];
            for (char &c : bits) {
                c = (c == '0') ? '1' : '0';
            }
            reverse(bits.begin(), bits.end());
            vec[i] = vec[i-1] + "1" + bits;
        }
        return vec[n-1][k-1];
    }
};