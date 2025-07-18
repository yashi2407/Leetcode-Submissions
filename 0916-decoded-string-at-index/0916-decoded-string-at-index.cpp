class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
                size+=1;
            }
            else{
                size *= (s[i] - '0');
            }
        }
        string kth = " ";
        for(int i = s.size()-1;i>=0;i--){
            if(isdigit(s[i])){
                size = size / (s[i]-'0');
                k = k % size == 0 ? size : k% size;
            }
            else {
                if(k==size){
                    return string(1, s[i]);
                }
                size --;
            }
        }
        return "";
    }
};