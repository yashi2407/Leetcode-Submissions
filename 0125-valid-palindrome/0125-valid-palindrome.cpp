class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<=j){
            if (isalnum(s[i]) && isalnum(s[j])) {
                // both are alphabet
                // see if they are same or not
                if(tolower(s[i]) != tolower(s[j])){
                    return false;
                }
                else{
                    i++;
                    j--;
                }
            }
            else if(isalnum(s[i]) && !isalnum(s[j])){
                j--;
            }
            else{
                i++;
            }
        }
        return true;
    }
};