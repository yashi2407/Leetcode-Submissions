class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int area = INT_MIN;
        while(i<j){
            if(height[i]>height[j]){
                area= max(area, height[j]* (j-i));
                j--;
            }
            else{
                area= max(area, height[i]* (j-i));
                i++;
            }
        }
        return area;
    }
};