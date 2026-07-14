class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftCount = 0;
        int rightCount = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                leftCount++;
            }
            else {
                if(leftCount>0){
                    leftCount--;
                }
                else{
                    rightCount++;
                }
                
            }
        }
        return leftCount + rightCount;
    }
};