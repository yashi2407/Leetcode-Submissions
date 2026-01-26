class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int minDifference = INT_MAX;
        for(int i = 0;i<arr.size()-1;i++){
            int currentDifference = abs(arr[i+1] - arr[i]);
            // found a new minDifference
            if(minDifference>=currentDifference){
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);
                if(minDifference>currentDifference){
                    ans.clear();
                }
                ans.push_back(temp);
                minDifference = currentDifference;
            }
        }
        return ans;
    }
};