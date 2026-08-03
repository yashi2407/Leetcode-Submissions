class Solution {
public:
    bool hasLeadingZero(string &firstHalf){
        if(firstHalf.size()>1 && firstHalf[0] == '0'){
            return true;
        }
        return false;
    }
    void util(string s, vector<string>&ans, int index, int dotsRemaining, string &currentAns){
        if (index >= s.size()) {
            if (dotsRemaining == 0) {
                ans.push_back(currentAns.substr(0, currentAns.size() - 1));
            }
            return;
        }
        // try possible places
        for(int i=0;i<=2;i++){
            cout<<"i+1 is"<<i+1;
            string firsthalf="";
            if (index + i + 1 <= s.size()){
                firsthalf = s.substr(index,i+1);
                if(stoi(firsthalf)>=0 && stoi(firsthalf)<=255 && !hasLeadingZero(firsthalf)){
                    currentAns+= firsthalf;
                    currentAns +='.';
                    util(s,ans,index+i+1,dotsRemaining-1,currentAns);
                    currentAns.pop_back();
                    currentAns.resize(currentAns.length() - firsthalf.length());
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string currentAns = "";
        util(s,ans,0,4,currentAns);
        return ans;
    }
};