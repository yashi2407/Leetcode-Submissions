class Solution {
public:
    int reverseBits(int n) {
        int result = 0;
        for(int i=0;i<32;i++){
            // make space for new bit. but doing left shift
            result = result << 1;
            // append the MSB of n at newly created place 
            result = result | (n & 1);
            // remove the last bit
            n = n>>1;
        }
        return result;
    }
};