class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // Count frequencies of values in tops array
        map<int, int> topFreq;
        int topMaxCount = 0;
        int topMaxElement = 0;
        
        for (int i = 0; i < tops.size(); i++) {
            topFreq[tops[i]]++;
            if (topFreq[tops[i]] >= topMaxCount) {
                topMaxCount = topFreq[tops[i]];
                topMaxElement = tops[i];
            }
        }
        
        // Count frequencies of values in bottoms array
        map<int, int> bottomFreq;
        int bottomMaxCount = 0;
        int bottomMaxElement = 0;
        
        for (int i = 0; i < bottoms.size(); i++) {
            bottomFreq[bottoms[i]]++;
            if (bottomFreq[bottoms[i]] >= bottomMaxCount) {
                bottomMaxCount = bottomFreq[bottoms[i]];
                bottomMaxElement = bottoms[i];
            }
        }
        
        int rotationsNeeded = 0;
        
        // Choose the array with more frequent max element
        if (topMaxCount > bottomMaxCount) {
            // Try to make all tops match topMaxElement
            for (int i = 0; i < tops.size(); i++) {
                if (tops[i] != topMaxElement) {
                    // Check if we can swap with bottom
                    if (bottoms[i] == topMaxElement) {
                        rotationsNeeded++;
                    } else {
                        // Can't make all dominoes show the same value
                        return -1;
                    }
                }
            }
        } else {
            // Try to make all bottoms match bottomMaxElement
            for (int i = 0; i < bottoms.size(); i++) {
                if (bottoms[i] != bottomMaxElement) {
                    // Check if we can swap with top
                    if (tops[i] == bottomMaxElement) {
                        rotationsNeeded++;
                    } else {
                        // Can't make all dominoes show the same value
                        return -1;
                    }
                }
            }
        }
        
        return rotationsNeeded;
    }
};