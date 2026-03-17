class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> topFreq;
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
        unordered_map<int, int> bottomFreq;
        int bottomMaxCount = 0;
        int bottomMaxElement = 0;
        
        for (int i = 0; i < bottoms.size(); i++) {
            bottomFreq[bottoms[i]]++;
            if (bottomFreq[bottoms[i]] >= bottomMaxCount) {
                bottomMaxCount = bottomFreq[bottoms[i]];
                bottomMaxElement = bottoms[i];
            }
        }
        int ans = 0;
        // top has more same element, we need to swap from bottom
        if(topMaxCount >= bottomMaxCount){
            for(int i=0;i<tops.size();i++){
                if(tops[i] != topMaxElement){
                    if(bottoms[i] != topMaxElement){
                        return -1;
                    }
                    else{
                        swap(tops[i], bottoms[i]);
                        ans++;
                    }
                }
            }
        }
        else{
            for(int i=0;i<bottoms.size();i++){
                if(bottoms[i] != bottomMaxElement){
                    if(tops[i] != bottomMaxElement){
                        return -1;
                    }
                    else {
                        swap(tops[i], bottoms[i]);
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};