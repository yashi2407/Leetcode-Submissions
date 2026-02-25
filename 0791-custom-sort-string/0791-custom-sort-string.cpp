class Solution {
public:
    string customSortString(string order, string s) {
        sort(s.begin(),s.end(),[order](char a, char b){
            // if char a appears before b in order,return true;
            int indexA = -1;
            int indexB = -1;
            for(int i=0;i<order.size();i++){
                if(order[i] == a){
                    indexA = i;
                }
                if(order[i] == b){
                    indexB = i;
                }
            }
            // Case 1: both are in order
            if (indexA != -1 && indexB != -1){
                // suppose index a = 2 , index b = 3;
                return indexA < indexB;
            }
            // we found a in order so a should appear first!
            if (indexA != -1){
                return true;
            }
            // Case 3: only b is in order
            if (indexB != -1){  
                return false;
            }
            // Case 4: neither in order
            return a < b;
        });
        return s;
    }
};