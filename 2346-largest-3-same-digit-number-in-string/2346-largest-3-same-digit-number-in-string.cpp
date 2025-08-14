class Solution {
public:
    string largestGoodInteger(string num) {
        string best = "";
        for (int i = 0; i < num.size()-2; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string triple = num.substr(i, 3);
                if (triple > best) best = triple;
            }
        }
        return best;
    }
};