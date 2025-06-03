class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mp;
        for(int i = 0;i<s.size();i++){
            mp[s[i]]=i;
        }
        int start = 0, end = 0;
        vector<int>ans;
        for(int i =0;i<s.size();i++){
            int lastOccurence = mp[s[i]];
            end = max(end,lastOccurence);
            if(i==end){
                // partition will happen
                ans.push_back(i-start+1);
                start = i+1;
            }
        }
        return ans;
    }
};