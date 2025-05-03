class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int,int> mp;
         map<int,int> mp1;
        // store the count of top elements
        int currentTopMaxCount = INT_MIN;
        int currentTopMaxElement = INT_MIN;
        for(int i = 0;i<tops.size();i++){
            mp[tops[i]]++;
            if(mp[tops[i]]>=currentTopMaxCount){
                currentTopMaxCount = mp[tops[i]];
                currentTopMaxElement = tops[i]; 
            }
        }
        int currentBottomMaxCount = INT_MIN;
        int currentBottomMaxElement = INT_MIN;
        for(int i = 0;i<bottoms.size();i++){
            mp1[bottoms[i]]++;
            if(mp1[bottoms[i]]>=currentBottomMaxCount){
                currentBottomMaxCount = mp1[bottoms[i]];
                currentBottomMaxElement = bottoms[i]; 
            }
        }
        int ans = 0;
        // if top has more maxelements
        if(currentTopMaxCount > currentBottomMaxCount){
            for(int i = 0;i<tops.size();i++){
                if(tops[i] != currentTopMaxElement){
                    // swap if bottom is equal to max element
                    if(bottoms[i] == currentTopMaxElement){
                        ans++;
                    }
                    else {
                        return -1;
                    }
                }
            }
        }
        else {
            for(int i = 0;i<tops.size();i++){
                if(bottoms[i] != currentBottomMaxElement){
                    // swap if bottom is equal to max element
                    if(tops[i] == currentBottomMaxElement){
                        ans++;
                    }
                    else {
                        return -1;
                    }
                }
            }
        }
        
        return ans;
    }
};