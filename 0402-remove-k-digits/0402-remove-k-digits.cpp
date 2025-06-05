class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack;
        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.back() > digit) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }
        while(k>0){
            stack.pop_back();
            k--;
        }
        int i = 0;
        while (i < stack.size() && stack[i] == '0') {
            i++;
        }
        string result = stack.substr(i);
        return result.empty() ? "0" : result;
    }
};