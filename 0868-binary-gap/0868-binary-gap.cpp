class Solution {
public:
    int binaryGap(int n) {
        while ((n & 1) == 0 && n != 0) {
            n = n >> 1;  // shift right and remove trailing zero's
        }
        if (n == 1) return 0;           

        int currentGap = 0, maxGap = 0;
        while (n > 0) {
            if ((n & 1) == 1) {                 
                maxGap = max(maxGap, currentGap);
                currentGap = 0;                      
            } else
                currentGap++;                         
            n >>= 1;                         
        }
        return maxGap + 1;
    }
};