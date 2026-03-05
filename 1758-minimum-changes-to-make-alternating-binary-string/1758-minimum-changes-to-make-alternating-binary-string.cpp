class Solution {
public:
    int minOperations(string s) {
        int count = 0; int count2=0;
        for(int i=0;i<s.size();i++){
            if(i%2 == 0){
                //010101
                if(s[i] == '1'){
                    count++;
                }
            }
            else{
                if(s[i] == '0'){
                    count++;
                }
            }
        }
        for(int i=0;i<s.size();i++){
            if(i%2!= 0){
                //odd index should be zero -- 10101010
                if(s[i] == '1'){
                    count2++;
                }
            }
            else {
                if(s[i] == '0'){
                    count2++;
                }
            }
        }
        return min(count,count2);
    }
};