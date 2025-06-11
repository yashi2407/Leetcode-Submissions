class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftCount=0,rightCount =0;
        for(char c : s){
            if(c=='('){
                leftCount++;
            }
            else if(c == ')'){
                if(leftCount>0){
                    leftCount--;
                }
                else{
                    rightCount++;
                }
            }
        }
        return leftCount+rightCount;
    }
};