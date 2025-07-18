class Solution {
public:
    char processStr(string s, long long k) {
        long long size = 0;
        k = k + 1;
        for(int i=0;i<s.size();i++){
            if(s[i]== '*'){
                if (size > 0) size--;
            }
            else if(s[i] == '#'){
                size = size * 2;
            }
            else if( s[i] == '%'){
                continue;
            }
            else{
                size++;
            }
        }
        if (k > size || k <= 0) return '.';
        for(int i =s.size()-1;i>=0;i--){
            if(!isalpha(s[i])){
                if(s[i]== '*'){
                    size++;
                }
                else if(s[i] == '#'){
                    if (size > 0) {
                        size = size / 2;
                        k = (k % size == 0) ? size : (k % size);
                    }
                }
                else if( s[i] == '%'){
                    k = size - k + 1;
                }
            }
            else {
                if(k==size){
                    return s[i];
                }
                else{
                    size--;
                }
            }
        }
        return '.';
    }
};