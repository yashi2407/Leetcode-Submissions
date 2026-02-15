class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;
        int i = a.size()-1;
        int j = b.size()-1;
        while(i>=0 && j>=0){
            int sum = carry + (a[i] - '0') + (b[j] - '0');
            if(sum>1){
                carry = 1;
            }
            else{
                carry = 0;
            }
            ans.push_back(sum%2 == 0 ? '0' : '1');
            i--;
            j--;
        }
        // if one string hasn't 
        while(i>=0){
            int sum = carry + (a[i] - '0');
            if(sum>1){
                carry = 1;
            }
            else{
                carry = 0;
            }
            ans.push_back(sum%2 == 0 ? '0' : '1');
            i--;
        }
        while(j>=0){
            int sum = carry + (b[j] - '0');
            if(sum>1){
                carry = 1;
            }
            else{
                carry = 0;
            }
            ans.push_back(sum%2 == 0 ? '0' : '1');
            j--;
        }
        if(carry == 1){
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};