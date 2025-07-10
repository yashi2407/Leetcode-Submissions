class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int>freeTime;
        freeTime.push_back(startTime[0]);
        for(int i=1;i<startTime.size();i++){
            freeTime.push_back(startTime[i]-endTime[i-1]);
        }
        freeTime.push_back(eventTime-endTime[endTime.size()-1]);
        int n = freeTime.size();
        vector<int>maxRight(n,0);
        vector<int>maxLeft(n,0);
        for(int i = n-2;i>=0;i--){
            maxRight[i]= max(maxRight[i+1],freeTime[i+1]);
        }
        for(int i = 1;i<n;i++){
            maxLeft[i]= max(maxLeft[i-1],freeTime[i-1]);
        }
        int result = 0;
        //Iterating on the freeArray
        for(int i = 1; i < n; i++) {
            int currEventTime = endTime[i-1] - startTime[i-1]; //duration of event = d

            //Case-1 Moving completely out
            if(currEventTime <= max(maxLeft[i-1], maxRight[i])) {
                result = max(result, freeTime[i-1] + currEventTime + freeTime[i]);
            }

            //case-2 shift left or right
            result = max(result, freeTime[i-1] + freeTime[i]);
        }

        return result;



    }
};