class Solution {
public:
    long long computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long long intersection_x = max(0, min(ax2,bx2)- max(ax1,bx1));
        long long intersection_y = max(0, min(ay2,by2)- max(ay1,by1));
         
        long long side = min(intersection_x, intersection_y);
        long long area = side * side;
        return area;
    }
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0;
        for(int i = 0;i<bottomLeft.size();i++){
            // rectangle number 1
            int ax1 = bottomLeft[i][0];
            int ay1 = bottomLeft[i][1];
            int ax2 = topRight[i][0];
            int ay2 = topRight[i][1];
            for(int j = 0; j!=i && j<bottomLeft.size();j++){
                // rectangle number 1
                int bx1 = bottomLeft[j][0];
                int by1 = bottomLeft[j][1];
                int bx2 = topRight[j][0];
                int by2 = topRight[j][1];
                ans = max(ans,computeArea(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2));
            }
        }
        return ans;
    }
};