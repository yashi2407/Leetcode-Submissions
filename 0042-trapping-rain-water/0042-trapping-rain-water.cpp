class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>greatestToLeft = height;
        // fill greatest to left array
        for(int i = 1;i<height.size();i++){
            greatestToLeft[i] = max(greatestToLeft[i-1],height[i]);
        }
        vector<int>greatestToRight = height;
         // fill greatest to right array
        for(int i = height.size()-2;i>=0;i--){
            greatestToRight[i] = max(greatestToRight[i+1],height[i]);
        }
        int water = 0;
        for(int i =0;i<height.size();i++){
            water = water + (min(greatestToLeft[i],greatestToRight[i]))-height[i];
        }
        return water;
    }
};