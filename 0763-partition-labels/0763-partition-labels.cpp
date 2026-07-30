class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]] = i;
        }
        vector<int>ans;
        int start = 0;
        int lastIndex = 0;
        for(int i = 0;i<s.size();i++){
            char c = s[i];
            lastIndex = max(lastIndex,mp[c]);
            cout<<"char is"<<c<<"lastIndex"<<lastIndex<<endl;
            if(i == lastIndex){
                ans.push_back(i-start+1);
                start = i+1;
                lastIndex= i+1;
            }

        }
        return ans;
    }
};