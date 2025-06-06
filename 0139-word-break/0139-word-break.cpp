class Solution {
public:
    bool util(string s,unordered_map<string,int>&mp,unordered_map<string,bool>&memo){
        if(s.size()==0){
            return true;
        }
        if(memo.find(s)!=memo.end()){
            return memo[s];
        }
        for(int i = 1;i<=s.size();i++){
            string temp = s.substr(0,i);
            cout<<temp<<" ";
            if(mp.find(temp)!=mp.end()){
                if(util(s.substr(i),mp,memo)){
                    return memo[s]= true;
                }
            }
        }
        return memo[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(int i=0;i<wordDict.size();i++){
            mp[wordDict[i]]++;
        }
        unordered_map<string,bool> memo;
        return util(s,mp,memo);
    }
};