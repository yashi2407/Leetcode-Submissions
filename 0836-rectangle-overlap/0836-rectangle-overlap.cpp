class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int ax1 = rec1[0];
        int ax2 = rec1[2];
        int bx1 = rec2[0];
        int bx2 = rec2[2];
        // get y coordinates
        int ay1 = rec1[1];
        int ay2 = rec1[3];
        int by1 = rec2[1];
        int by2 = rec2[3];
        
        int intersection_x = min(ax2,bx2) - max(ax1,bx1);
        int intersection_y = min(ay2,by2) - max(ay1,by1);
        if(intersection_x>0 && intersection_y>0){
            return true;
        }
        return false;
    }
};