class Solution {
public:
    unordered_set<string>allPasswords;
    int totalPasswords;
    string getLastNDigits(string currentPassword, int n){
        return currentPassword.substr(currentPassword.size()-n);
    }
    bool util(string &currentPassword, int n, int k) {
        if(allPasswords.size() == totalPasswords){
            return true;
        }

        for(int i=0;i<=k-1;i++){
            currentPassword+=to_string(i);
            string lastDigits = getLastNDigits(currentPassword,n);
            if(allPasswords.find(lastDigits) == allPasswords.end()){
                allPasswords.insert(lastDigits);
                if(util(currentPassword,n,k)){
                    return true;
                }
                allPasswords.erase(lastDigits);
            }
            currentPassword.pop_back();
        }
        return false;
    }
    string crackSafe(int n, int k) {
        totalPasswords = pow(k,n);
        string currentPassword(n, '0');
        // Mark it as already included
        allPasswords.insert(currentPassword);
        util(currentPassword, n, k);
        return currentPassword;

    }
};