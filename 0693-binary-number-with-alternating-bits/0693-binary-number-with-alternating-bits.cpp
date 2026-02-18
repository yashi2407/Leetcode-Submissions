class Solution {
public:
    bool hasAlternatingBits(int n) {
        // get the MSB currently
        int lastBit = n & 1;
        n = n >> 1;
        while(n>0){
            int currentBit =  n & 1;
            // if it's same as the last bit
            if(lastBit == currentBit){
                return false;
            }
            lastBit = currentBit;
            n = n>>1;
        }
        return true;
    }
};