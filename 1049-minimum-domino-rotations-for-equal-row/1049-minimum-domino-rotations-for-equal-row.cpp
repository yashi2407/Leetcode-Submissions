class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int rotationsNeeded = tryValue(tops[0], tops, bottoms, n);
        
        // If tops[0] doesn't work, try bottoms[0]
        if (rotationsNeeded != -1) return rotationsNeeded;
        return tryValue(bottoms[0], tops, bottoms, n);
    }
    
private:
    // Try to make all dominoes have value 'target' on top side
    int tryValue(int target, vector<int>& tops, vector<int>& bottoms, int n) {
        int topRotations = 0;   // rotations needed if we want target on top
        int bottomRotations = 0;  // rotations needed if we want target on bottom
        
        for (int i = 0; i < n; i++) {
            // If neither top nor bottom matches target, it's impossible
            if (tops[i] != target && bottoms[i] != target) {
                return -1;
            }
            
            // Count rotations needed to get target on top
            if (tops[i] != target) topRotations++;
            
            // Count rotations needed to get target on bottom
            if (bottoms[i] != target) bottomRotations++;
        }
        
        // Return the minimum number of rotations
        return min(topRotations, bottomRotations);
    }
};