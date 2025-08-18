class Solution {
public:
    double solve(double num1, double num2, char s){
            switch(s){
                case '+': return num1 + num2;
                case '-': return num1 - num2;
                case '*': return num1 * num2;
                case '/': return num1 / num2;
            }
            return 0; // fallback, though we never reach here
        }
    bool util(vector<double>list){
        // can pick any two numbers!
        if(list.size() == 1){
            return fabs(list[0] - 24.0) < 1e-6;
        }
        vector<char> possibleOperation = {'+','-','*','/'};
        for(int i = 0;i<list.size()-1;i++){
            for (int j = i+1;j<list.size();j++){
                // try out all possible combinations on these two numbers!
                for(int k = 0;k<possibleOperation.size();k++){
                    double number1 = list[i];
                    double number2 = list[j];
                    // copy all elements in list apart from num1 and num2.

                    vector<double> nextCards;
                    for (int t = 0; t < list.size(); t++) {
                        if (t != i && t != j) {
                            nextCards.push_back(list[t]);
                        }
                    }
                    if(possibleOperation[k] == '/' && fabs(number2) < 1e-6) continue; 
                    double ans = solve(number1,number2,possibleOperation[k]);
                    nextCards.push_back(ans);
                    if(util(nextCards)){
                        return true;
                    }
                    nextCards.pop_back();
                    if(possibleOperation[k]== '-' || possibleOperation[k] == '/'){
                        if(possibleOperation[k] == '/' && fabs(number1) < 1e-6) continue;
                        double ans = solve(number2,number1,possibleOperation[k]);
                        nextCards.push_back(ans);
                        if(util(nextCards)){
                            return true;
                        }
                        nextCards.pop_back();
                    }

                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> start(cards.begin(), cards.end());
        return util(start);
    }
};