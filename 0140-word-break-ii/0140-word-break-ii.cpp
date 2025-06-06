class Solution {
public:
    void util(string s, string current, unordered_map<string,int>&mp,vector<string> &ans){
        if(s.size()==0){
            ans.push_back(current.substr(0, current.size() - 1));
            return;
        }
        for(int i = 1;i<=s.size();i++){
            string temp = s.substr(0,i);
            if(mp.find(temp)!=mp.end()){
                util(s.substr(i),current+temp+" ",mp,ans);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       vector<string> ans;
       string current="";
       unordered_map<string,int>mp;
        for(int i=0;i<wordDict.size();i++){
            mp[wordDict[i]]++;
        }
       util(s,current,mp,ans);
       return ans; 
    }
};