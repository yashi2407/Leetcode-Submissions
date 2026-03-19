class Solution {
public:
    string getLastNDigits(string s, int n) {
        if (n >= s.size()) return s;
        return s.substr(s.size() - n);
    }
    bool start(int n, int k, string &currentPassword, set<string>&allPasswords, int total){
        if(allPasswords.size() == total){
            return true;
        }
        for(int i = 0;i<k;i++){
            currentPassword += to_string(i);
            // see if last n digits have been formed or not
            string last = getLastNDigits(currentPassword,n);
            if(allPasswords.find(last) == allPasswords.end()){
                allPasswords.insert(last);
                if(start(n,k,currentPassword,allPasswords,total)){
                    return true;
                }
                allPasswords.erase(last);
            }
            currentPassword.pop_back();
        }
        return false;
    }
    string crackSafe(int n, int k) {
        set<string>allPasswords;
        string currentPassword(n - 1, '0');
        int total = 1;
        for (int i = 0; i < n; i++) total *= k;
        start(n,k,currentPassword,allPasswords,total);
        return currentPassword;

    }
};