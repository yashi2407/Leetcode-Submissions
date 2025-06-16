class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        vector<int>lis;
        for(int i=0;i<obstacles.size();i++){
            int index = upper_bound(lis.begin(),lis.end(),obstacles[i])-lis.begin();
            if(index==lis.size()){
                // contiue the sueqequence
                lis.push_back(obstacles[i]);
            }
            else {
                lis[index]=obstacles[i];
            }
            ans.push_back(index+1);
        }
        return ans;
    }
};