class Solution {
public:
    void util(string &s,vector<string> &ans, int index){
        if(index>=s.size()){
            ans.push_back(s);
            return;
        }
        // if uppercase, change to lowercase
        if (islower(s[index])){
            s[index] = toupper(s[index]);
            util(s,ans,index+1);
            s[index] = tolower(s[index]);
        }

        else if (isupper(s[index])){
            s[index] = tolower(s[index]);
            util(s,ans,index+1);
            s[index] = toupper(s[index]);
        }
        // keep it as is
        util(s,ans,index+1);
        


    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        util(s,ans,0);
        return ans;
    }
};