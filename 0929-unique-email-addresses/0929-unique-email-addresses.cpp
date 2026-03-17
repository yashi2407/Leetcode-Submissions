class Solution {
public:
    string formatEmail(string s){
        string ans = "";
        int pos = s.find('@');
        string localName  = s.substr(0, pos);
        string domain = s.substr(pos + 1);
        // format localName
        for(int i = 0; i<localName.size();i++){
            if(localName[i] == '.'){
                continue;
            }
            else if(localName[i] == '+'){
                break;
            }
            else{
                ans += localName[i];
            }
        }
        ans =  ans + '@' + domain;
        return ans;
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int>mp;
        for(int i = 0 ;i<emails.size();i++){
            string currentEmail = emails[i];
            string formattedEmail = formatEmail(currentEmail);
            mp[formattedEmail]++;
        }
        return mp.size();
    }
};