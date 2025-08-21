class Solution {
public:
    bool allZero(vector<int>& count) {
        for (int x : count) {
            if (x != 0) return false;
        }
        return true;
    }
    void util(vector<vector<int>>& requests, int index, int currentCount, vector<int>&count, int &result){
        if(index >= requests.size()){
            if(allZero(count)){
                result = max(result,currentCount);
                return;
            }
            return;
        }

        // take the current request!
        int sourceOffice = requests[index][0];
        int destinationOffice = requests[index][1];
        count[sourceOffice]--;
        count[destinationOffice]++;
        // move onto the next request!
        util(requests, index+1,currentCount+1,count,result);

        // Backtrack
        count[sourceOffice]++;
        count[destinationOffice]--;
        util(requests, index+1,currentCount,count,result);

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>count(n,0);
        int result = INT_MIN;
        util(requests,0,0,count,result);
        return result;
    }
};