class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string>letterLogs;
        vector<string>digitLogs;
        for(int i=0;i<logs.size();i++){
            string log = logs[i];
            for(int j=0;j<log.size();j++){
                if(log[j]== ' '){
                    // check the next
                    if((log[j+1] - '0') >=0 && (log[j+1]-'0')<=9){
                        // it's a digit log
                        digitLogs.push_back(log);
                    }
                    else{
                        // letter logs!
                        letterLogs.push_back(log);
                    }
                    break;
                }
            }
        }
        sort(letterLogs.begin(),letterLogs.end(),[] (const string&a, const string &b){
            int aIden = a.find(' ');
            string aidentifier = a.substr(0, aIden);
            string acontent = a.substr(aIden + 1);

            int bIden = b.find(' ');
            string bidentifier = b.substr(0, bIden);
            string bcontent = b.substr(bIden + 1);
            if(acontent!=bcontent){
                return acontent<bcontent;
            }
            else{
                return aidentifier<bidentifier;
            }
        });
        for(int i=0;i<digitLogs.size();i++){
            letterLogs.push_back(digitLogs[i]);
        }
        return letterLogs;
    }
};