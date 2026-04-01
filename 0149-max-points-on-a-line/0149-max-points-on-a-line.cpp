class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=0;i<points.size();i++){
            // put {dy,dx}
            map<pair<int,int>,int>mp;
            int maxCount = 0;
            for(int j = 0;j<points.size();j++){
                if(i==j){
                    continue;
                }
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                int g = gcd(abs(dy), abs(dx));
                dy /= g;
                dx /= g;
                if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                } else if (dx == 0) {
                    dy = 1;
                } else if (dy == 0) {
                    dx = 1;
                }
                mp[{dy, dx}]++;
                maxCount = max(maxCount, mp[{dy, dx}]);

            }
            ans = max(ans,maxCount+1);
        }
        return ans;
    }
};