class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for(int i = digits.size()-1;i>=0;i--){
            int sum = digits[i] + carry;
            if(i == digits.size()-1){
                sum+=1;
            }
            if(sum<=9){
                digits[i] = sum;
                carry = 0;
                break;
            }
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if(carry == 1){
            digits.insert(digits.begin(), 1); 
        }
        return digits;
    }
};